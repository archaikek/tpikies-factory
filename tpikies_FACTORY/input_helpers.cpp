#include "input_helpers.h"

int *get_groups(int *n)
{
	scanf("%d", n);
	const int size = *n;
	int *groups = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i)
	{
		scanf("%d", groups + i);
	}
	return groups;
}
int *get_slots(int *m)
{
	scanf("%d", m);
	const int size = *m;
	int *slots = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i)
	{
		scanf("%d", slots + i);
	}
	return slots;
}
residual_graph_t *get_graph(const int n, const int m, const int *groups, const int *slots)
{
	residual_graph_t *graph = create_graph(n + 2 * m);
	std::vector<edge_t> **gr = graph->graph;
	
	// connect supersource to groups
	for (int i = 0; i < n; ++i)
	{
		// groups indexed from 1 to n inclusive
		gr[0]->push_back({ i + 1, groups[i], 0 });
	}

	// connect groups to slots
	int is_connected;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &is_connected);
			if (is_connected)
			{
				// slots indexed from n + 1 to n + m inclusive, flow unlimited
				gr[i]->push_back({ n + 1 + j, INF, 0 });
			}
		}
	}

	// move weights from slot nodes to edges
	for (int i = 0; i < m; ++i)
	{
		// slot helper nodes indexed from n + m + 1 to n + 2m inclusive
		gr[n + 1 + i]->push_back({ n + m + 1 + i, slots[i], 0 });
	}

	// connect slot helper nodes to superdrain
	for (int i = 0; i < m; ++i)
	{
		gr[n + m + 1 + i]->push_back({ n + 2 * m + 1, INF, 0 });
	}

	return graph;
}