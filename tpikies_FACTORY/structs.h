#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>

#define INF ((1<<31) - 1)
#define DEBUG

typedef struct edge_t
{
	int dest;
	int capacity, residue;
};
typedef struct residual_graph_t
{
	std::vector<edge_t> **graph;
	int node_count;
};

residual_graph_t *create_graph(const int node_count);
void delete_graph(residual_graph_t *graph);

#ifdef DEBUG
void print_edge(const edge_t edge);
void print_edge_with_source(const edge_t edge, const int src);

void print_graph(const residual_graph_t *graph);
#endif