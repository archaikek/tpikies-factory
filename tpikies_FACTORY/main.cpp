#include "structs.h"
#include "input_helpers.h"
#include "maxflow_functions.h"

int main()
{
	int n, m, result = 0;

	int *groups = get_groups(&n);
	int *slots = get_slots(&m);
	residual_graph_t *graph = get_graph(n, m, groups, slots);

	print_graph(graph);

#ifdef DEBUG
	init_maxflow_helper_variables(graph->node_count + 2);
	std::vector<int> *path = bfs(graph);
	printf("\nPath: ");
	for (int i = 0; i < path->size(); ++i)
	{
		printf("%d ", (*path)[i]);
	}
	printf("\n");
	clear_maxflow_helper_variables();
#endif


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
*/