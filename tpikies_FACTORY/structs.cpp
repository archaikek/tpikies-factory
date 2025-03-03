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