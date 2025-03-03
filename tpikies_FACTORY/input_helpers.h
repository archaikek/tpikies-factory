#pragma once
#include "structs.h"

int *get_groups(int *n);
int *get_slots(int *m);
residual_graph_t *get_graph(const int n, const int m, const int *groups, const int *slots);