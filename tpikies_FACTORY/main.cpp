#include "structs.h"
#include "input_helpers.h"

int main()
{
	int n, m, result = 0;

	int *groups = get_groups(&n);
	int *slots = get_slots(&m);
	residual_graph_t *graph = get_graph(n, m, groups, slots);

	print_graph(graph);


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