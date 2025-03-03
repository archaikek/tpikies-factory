#pragma once
#include "structs.h"
#include <queue>

void init_maxflow_helper_variables(const int node_count);
void clear_maxflow_helper_variables();

std::vector<int> *bfs(residual_graph_t *graph);
int maxflow(const residual_graph_t *graph);