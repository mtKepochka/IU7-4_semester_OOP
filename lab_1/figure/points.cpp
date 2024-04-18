#include "points.h"

points_t points_default()
{
    return points_t{NULL, 0};
}

errors_t allocate_points(points_t &points)
{
    errors_t rc = SUCCESS;
    if (points.size <= 0)
        rc = SIZE_POINTS_ERROR;
    else
    {
        point_t *temp = (point_t *) malloc(points.size * sizeof(point_t));
        if (!temp)
            rc = MEMORY_ALLOCATE_ERROR;
        else
            points.array_points = temp;
    }

    return rc;
}

errors_t free_points(points_t &points)
{
    free(points.array_points);
    points = points_default();
    return SUCCESS;
}

errors_t read_inf_about_points(points_t &points, FILE *fin)
{
    if (fin == NULL)
        return FILE_OPEN_ERROR;

    errors_t rc = read_amount_points(points, fin);
    if (!rc)
    {
        rc = allocate_points(points);
        if (!rc)
        {
            rc = read_points(points, fin);
            if (rc)
                free_points(points);
        }
    }
    return rc;
}

errors_t read_amount_points(points_t &points, FILE *fin)
{
    errors_t rc = SUCCESS;
    if (fin == NULL)
        rc = FILE_OPEN_ERROR;
    else if (fscanf(fin, "%d", &points.size) != 1)
        rc = READ_FILE_ERROR;
    else if (points.size <= 0)
        rc = SIZE_POINTS_ERROR;

    return rc;
}

errors_t read_points(points_t &points, FILE *fin)
{
    errors_t rc = SUCCESS;
    if (fin == NULL)
        rc = FILE_OPEN_ERROR;
    else if (points.size <= 0)
        rc = SIZE_POINTS_ERROR;
    else if (!points.array_points)
        rc = MEMORY_ALLOCATE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < points.size; i++)
            rc = read_point(points.array_points[i], fin);

    return rc;
}

errors_t move_points(points_t &points, const move_t &coeff)
{
    if (!points.array_points)
        return FIGURE_NOT_LOADED;

    for (int i = 0; i < points.size; i++)
        move_point(points.array_points[i], coeff);

    return SUCCESS;
}

errors_t rotate_points(points_t &points, const point_t &r_center, const rotate_t &coeff)
{
    if (!points.array_points)
        return FIGURE_NOT_LOADED;

    for (int i = 0; i < points.size; i++)
        rotate_point(points.array_points[i], r_center, coeff);

    return SUCCESS;
}

errors_t scale_points(points_t &points, const point_t &s_center, const scale_t &coeff)
{
    if (!points.array_points)
        return FIGURE_NOT_LOADED;

    for (int i = 0; i < points.size; i++)
        scale_point(points.array_points[i], s_center, coeff);

    return SUCCESS;
}

errors_t save_points(const points_t &points, FILE *fout)
{
    errors_t rc = SUCCESS;
    if (!points.array_points)
        rc = NO_DATA_WRITE_ERROR;
    else if (fprintf(fout, "%d\n", points.size) < 0)
        rc = FILE_WRITE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < points.size; i++)
            rc = save_point(points.array_points[i], fout);

    return rc;
}
