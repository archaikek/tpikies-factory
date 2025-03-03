#pragma once
#include "structs.h"

void read_table_and_size(int *size, int **tab);
int *get_groups(int *n);
int *get_slots(int *m);
residual_graph_t *get_graph(const int n, const int m, const int *groups, const int *slots);