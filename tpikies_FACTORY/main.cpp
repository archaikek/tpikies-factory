#include "structs.h"
#include "input_helpers.h"
#include "maxflow_functions.h"

int main()
{
	int n, m, t, result = 0;

	int *groups = get_groups(&n);
	int *slots = get_slots(&m);
	residual_graph_t *graph = get_graph(n, m, groups, slots);
	scanf("%d", &t);


#ifdef DEBUG
	print_graph(graph);

	init_maxflow_helper_variables(graph->node_count + 2);
	std::vector<int> *path = bfs(graph);
	printf("\nPath: ");
	for (int i = 0; i < path->size(); ++i)
	{
		printf("%d ", (*path)[i]);
	}
	printf("\n");
	delete path;
	clear_maxflow_helper_variables();
#endif

	init_maxflow_helper_variables(graph->node_count + 2);
	result = maxflow(graph);
	clear_maxflow_helper_variables();

	printf("%d\n", result);
	if (t)
	{
		std::vector<edge_t> **gr = graph->graph;
		for (int i = 1; i <= n; ++i)
		{
			int index = 1; // index 0 is always residual edge
			edge_t *node = &(*gr[i])[0];
			for (int j = 1; j <= m; ++j)
			{
				if (node[index].dest == n + j) // if the next slot is connected to the group
				{
					printf("%d ", (*gr[n + j])[node[index++].residue_index].capacity);
				}
				else
				{
					printf("0 ");
				}
			}
			printf("\n");
		}
	}

	delete_graph(graph);
	free(slots);
	free(groups);
	return 0;
}

/*
4 
2 13 3 5
3 
10 5 12
0 1 0
0 1 1
1 1 0
1 1 0
0

4 
1 1 1 1
4 
1 1 1 1
0 1 0 0
0 1 1 0
0 0 1 1
1 0 1 1
1
*/