#include "maxflow_functions.h"

static int *previous_node, *previous_index, *visited, run_count;

void init_maxflow_helper_variables(const int node_count)
{
	previous_node = (int *)malloc(sizeof(int) * node_count);
	previous_index = (int *)malloc(sizeof(int) * node_count);
	visited = (int *)malloc(sizeof(int) * node_count);

	for (int i = 0; i < node_count; ++i)
	{
		previous_node[i] = previous_index[i] = visited[i] = run_count = 0;
	}
}
void clear_maxflow_helper_variables()
{
	free(visited);
	free(previous_index);
	free(previous_node);
}

std::vector<int> *bfs(residual_graph_t *graph)
{
	std::vector<int> *path = new std::vector<int>();
	std::vector<edge_t> **gr = graph->graph;
	const int node_count = graph->node_count;
	int curr_node = 0;
	visited[0] = ++run_count;

	std::queue<int> *queue = new std::queue<int>();
	queue->push(0);
	// while not in superdrain and there is still something to use
	while (curr_node != node_count + 1 && !queue->empty())
	{
		curr_node = queue->front();
		queue->pop();

		std::vector<edge_t> *node = gr[curr_node];
		const int size = node->size();
		for (int i = 0; i < size; ++i)
		{
			if (visited[(*node)[i].dest] < run_count && (*node)[i].capacity > 0)
			{
				const int dest = (*node)[i].dest;

				visited[dest] = run_count;
				queue->push(dest);
				previous_node[dest] = curr_node;
				previous_index[dest] = i;
			}
		}
	}
	delete queue;

	if (curr_node == node_count + 1) // reached the superdrain, new augmenting path found
	{
		int augment = INF;
		while (curr_node != 0)
		{
			path->push_back(previous_index[curr_node]); // add **index** of the edge from the previous node to the current node
			curr_node = previous_node[curr_node]; // step back
			augment = std::min(augment, (*gr[curr_node])[path->back()].capacity); // get capacity of the edge used
		}
		std::reverse(path->begin(), path->end()); // the path was constructed back to front, so we need to reverse it
		path->push_back(augment); // keep the max flow of this path at the end of the vector

		return path;
	}
	else // the superdrain couldn't be reached, meaning that the max flow has been found, which will be denoted by an empty vector
	{
		return path;
	}
}

int maxflow(residual_graph_t *graph)
{
	int result = 0;

	return result;
}