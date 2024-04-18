#ifndef DRAW_FIGURE_H
#define DRAW_FIGURE_H

#include <QGraphicsScene>

#include "figure.h"
#include "points.h"

typedef struct
{
    QGraphicsScene *scene;
    double width;
    double height;
} view_t;

typedef struct
{
    point_t first_point;
    point_t second_point;
} line_t;

line_t get_points(const edge_t &edge, const point_t *array_points);

errors_t draw_line(const view_t &view, const point_t &p1, const point_t &p2);

errors_t draw_lines(const view_t &view, const points_t &points, const edges_t &edges);

errors_t draw_figure(const figure_t &figure, view_t &view);

errors_t clear_scene(const view_t &view);

#endif // DRAW_FIGURE_H
