#ifndef EDGES_H
#define EDGES_H

#include "errors.h"

typedef struct
{
    int first_point;
    int second_point;
} edge_t;

typedef struct
{
    edge_t *array_edges;
    int size;
} edges_t;

errors_t allocate_edges(edges_t &edges);

errors_t free_edges(edges_t &edges);

edges_t edges_default();

errors_t read_amount_edges(edges_t &edges, FILE *fin);

errors_t read_inf_about_edges(edges_t &edges, FILE *fin);

errors_t read_edges(edges_t &edges, FILE *fin);

errors_t read_edge(edge_t &edge, FILE *fin);

errors_t save_edges(const edges_t &edges, FILE *fin);

errors_t save_edge(const edge_t &edge, FILE *fin);

#endif // EDGES_H
