#pragma once
#include <vector>

#define INF ((1<<31) - 1)

typedef struct edge_t
{
	int dest;
	int weight, residual_weight;
};
typedef struct residual_graph_t
{
	std::vector<edge_t> **graph;
	int node_count;
};

residual_graph_t *create_graph(const int node_count);
void delete_graph(residual_graph_t *graph);