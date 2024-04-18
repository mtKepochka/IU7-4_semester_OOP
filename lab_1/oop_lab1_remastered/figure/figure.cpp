#include "figure.h"

figure_t &figure_init(void)
{
    static figure_t figure;

    figure.center = point_default();

    figure.points = points_default();

    figure.edges = edges_default();

    return figure;
}

errors_t free_figure(figure_t &figure)
{
    free_points(figure.points);
    free_edges(figure.edges);
    return SUCCESS;
}

errors_t read_figure(figure_t &figure, FILE *fin)
{
    if (fin == NULL)
        return FILE_OPEN_ERROR;

    figure = figure_init();

    errors_t rc = read_inf_about_points(figure.points, fin);
    if (rc == SUCCESS)
    {
        rc = read_inf_about_edges(figure.edges, fin);
        if (rc)
            free_points(figure.points);
    }

    return rc;
}

errors_t download_figure(figure_t &figure, const char *filename)
{
    if (filename == NULL)
        return FILE_OPEN_ERROR;

    errors_t rc = SUCCESS;
    FILE *fin = fopen(filename, "r");
    if (fin == NULL)
        rc = FILE_OPEN_ERROR;
    else
    {
        figure_t current_figure;

        rc = read_figure(current_figure, fin);
        fclose(fin);
        if (rc == SUCCESS)
        {
            free_figure(figure);
            figure = current_figure;
        }

    }
    return rc;
}

errors_t move_figure(figure_t &figure, const move_t &move)
{
    move_point(figure.center, move);
    return move_points(figure.points, move);
}

errors_t scale_figure(figure_t &figure, const scale_t &scale)
{
    return scale_points(figure.points, figure.center, scale);
}

errors_t rotate_figure(figure_t &figure, const rotate_t &rotate)
{
    return rotate_points(figure.points, figure.center, rotate);
}

errors_t save_figure(figure_t &figure, const char *filename)
{
    errors_t rc = SUCCESS;
    if (filename == NULL)
        rc = FILE_WRITE_ERROR;
    else
    {
        FILE *fout = fopen(filename, "w");
        if (fout == NULL)
            rc = FILE_WRITE_ERROR;
        else
        {
            rc = save_points(figure.points, fout);
            if (rc == SUCCESS)
                rc = save_edges(figure.edges, fout);
            fclose(fout);
        }
    }
    return rc;
}
