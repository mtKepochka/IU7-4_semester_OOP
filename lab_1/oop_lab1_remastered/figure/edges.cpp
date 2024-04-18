#include "edges.h"

errors_t allocate_edges(edges_t &edges)
{
    errors_t rc = SUCCESS;
    if (edges.size <= 0)
        rc = SIZE_EDGES_ERROR;
    else
    {
        edge_t *temp = (edge_t *) malloc(edges.size * sizeof(edge_t));
        if (!temp)
            rc = MEMORY_ALLOCATE_ERROR;
        else
            edges.array_edges = temp;
    }
    return rc;
}

edges_t edges_default()
{
    return edges_t{NULL, 0};
}

errors_t free_edges(edges_t &edges)
{
    free(edges.array_edges);
    edges = edges_default();
    return SUCCESS;
}

errors_t read_edge(FILE *fin, edge_t &edge)
{
    errors_t rc = SUCCESS;
    if (fin == NULL)
        rc = FILE_OPEN_ERROR;
    else if (fscanf(fin, "%d %d", &edge.first_point,
                    &edge.second_point) != 2)
        rc = READ_FILE_ERROR;

    return rc;
}

errors_t read_edges(edges_t &edges, FILE *fin)
{
    errors_t rc = SUCCESS;
    if (fin == NULL)
        rc = FILE_OPEN_ERROR;
    else if (edges.size <= 0)
        rc = SIZE_EDGES_ERROR;
    else if (!edges.array_edges)
        rc = MEMORY_ALLOCATE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < edges.size; i++)
            rc = read_edge(fin, edges.array_edges[i]);

    return rc;
}


errors_t read_amount_edges(edges_t &edges, FILE *fin)
{
    errors_t rc = SUCCESS;
    if (fin == NULL)
        rc = FILE_OPEN_ERROR;
    else if (fscanf(fin, "%d", &edges.size) != 1)
        rc = READ_FILE_ERROR;
    else if (edges.size <= 0)
        rc = SIZE_POINTS_ERROR;

    return rc;
}


errors_t read_inf_about_edges(edges_t &edges, FILE *fin)
{
    if (fin == NULL)
        return FILE_OPEN_ERROR;

    errors_t rc = SUCCESS;
    rc = read_amount_edges(edges, fin);
    if (!rc)
    {
        rc = allocate_edges(edges);
        if (!rc)
        {
            rc = read_edges(edges, fin);
            if (rc)
                free_edges(edges);
        }
    }

    return rc;
}

errors_t save_edges(const edges_t &edges, FILE *fout)
{
    errors_t rc = SUCCESS;
    if (!edges.array_edges)
        rc = NO_DATA_WRITE_ERROR;
    else if (fprintf(fout, "%d\n", edges.size) < 0)
        rc = FILE_WRITE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < edges.size; i++)
            rc = save_edge(edges.array_edges[i], fout);

    return rc;
}

errors_t save_edge(const edge_t &edge, FILE *fout)
{
    int rc = fprintf(fout, "%d %d\n", edge.first_point, edge.second_point);
    if (rc < 0)
        return FILE_WRITE_ERROR;
    return SUCCESS;
}
