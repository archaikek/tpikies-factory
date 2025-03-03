#include "maxflow_functions.h"

static int *previous_node;
static bool *visited, is_even;

void init_maxflow_helper_variables(const int node_count)
{
	previous_node = (int *)malloc(sizeof(int) * node_count);
	visited = (bool *)malloc(sizeof(bool) * node_count);
	is_even = true; // 

	for (int i = 0; i < node_count; ++i)
	{
		previous_node[i] = 0;
		visited[i] = !is_even;
	}
}
void clear_maxflow_helper_variables(const int node_count);