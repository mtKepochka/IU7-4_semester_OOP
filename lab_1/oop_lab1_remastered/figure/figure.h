#ifndef FIGURE_H
#define FIGURE_H

#include "points.h"
#include "edges.h"
#include "actions_data.h"
#include "errors.h"

typedef struct
{
    point_t center;
    points_t points;
    edges_t edges;
} figure_t;

figure_t &figure_init(void);

errors_t free_figure(figure_t &figure);

errors_t read_figure(figure_t &figure, FILE *fin);

errors_t download_figure(figure_t &figure, const char *filename);

errors_t move_figure(figure_t &figure, const move_t &move);

errors_t scale_figure(figure_t &figure, const scale_t &scale);

errors_t rotate_figure(figure_t &figure, const rotate_t &rotate);

errors_t save_figure(figure_t &figure, const char *filename);

#endif // FIGURE_H
