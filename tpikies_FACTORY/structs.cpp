#include "structs.h"

residual_graph_t *create_graph(const int node_count)
{
	residual_graph_t *graph = (residual_graph_t *)malloc(sizeof(residual_graph_t));

	graph->node_count = node_count;
	// node_count only covers regular nodes of the graph (indexed 1 to n),
	// without the supersource and superdrain (nodes 0 and n+1)
	std::vector<edge_t> **gr = graph->graph = (std::vector<edge_t> **)malloc(sizeof(std::vector<edge_t> *) * (node_count + 2));
	for (int i = 0; i < node_count + 2; ++i)
	{
		gr[i] = new std::vector<edge_t>();
	}
	return graph;
}
void delete_graph(residual_graph_t *graph)
{
	const int node_count = graph->node_count;
	std::vector<edge_t> **gr = graph->graph;
	for (int i = 0; i < node_count + 2; ++i)
	{
		delete gr[i];
	}
	free(gr);
	free(graph);
}

#ifdef DEBUG
void print_edge(const edge_t edge)
{
	if (edge.capacity >= INF / 2) printf("%d (%d/INF)", edge.dest, edge.residue);
	else printf("%d (%d/%d)", edge.dest, edge.residue, edge.capacity);
}
void print_edge_with_source(const edge_t edge, const int src)
{
	if (edge.capacity >= INF / 2) printf("[%d -> %d (%d/INF)]", src, edge.dest, edge.residue);
	else printf("[%d -> %d (%d/%d)]", src, edge.dest, edge.residue, edge.capacity);
}

void print_graph(const residual_graph_t *graph)
{
	const int node_count = graph->node_count;
	std::vector<edge_t> **gr = graph->graph;

	for (int i = 0; i < node_count + 2; ++i)
	{
		std::vector<edge_t> *node = gr[i];
		const int size = node->size();

		printf("%d: ", i);
		if (size > 0)
		{
			print_edge((*node)[0]);
			for (int j = 1; j < size; ++j)
			{
				printf(", ");
				print_edge((*node)[j]);
			}
		}
		printf("\n");
	}
}
#endif