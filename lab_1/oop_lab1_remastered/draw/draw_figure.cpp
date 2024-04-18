#include "draw_figure.h"

line_t get_points(const edge_t &edge, const point_t *array_points)
{
    line_t line;

    line.first_point = array_points[edge.first_point];
    line.second_point = array_points[edge.second_point];

    return line;
}

errors_t clear_scene(const view_t &view)
{
    if (!view.scene)
        return SCENE_DRAW_ERROR;

    view.scene->clear();
    return SUCCESS;
}

errors_t draw_line(const view_t &view, const point_t &p1, const point_t &p2)
{
    if (!view.scene)
        return SCENE_DRAW_ERROR;

    view.scene->addLine(p1.x, p1.y, p2.x, p2.y);
    return SUCCESS;
}

errors_t draw_lines(const view_t &view, const points_t &points, const edges_t &edges)
{
    errors_t rc = SUCCESS;
    if (points.array_points == NULL || edges.array_edges == NULL)
        rc = MEMORY_ALLOCATE_ERROR;
    else if (!view.scene)
        rc = SCENE_DRAW_ERROR;
    else
    {
        line_t line;
        for (int i = 0; rc == SUCCESS && i < edges.size; i++)
        {
            line = get_points(edges.array_edges[i], points.array_points);
            rc = draw_line(view, line.first_point, line.second_point);
        }
    }

    return rc;
}

errors_t draw_figure(const figure_t &figure, view_t &view)
{
    errors_t rc = clear_scene(view);
    if (!rc)
        rc = draw_lines(view, figure.points, figure.edges);

    return rc;
}
