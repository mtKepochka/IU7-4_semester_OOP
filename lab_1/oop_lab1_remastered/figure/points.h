#ifndef POINTS_H
#define POINTS_H

#include "point.h"
#include "errors.h"

typedef struct
{
    point_t *array_points;
    int size;
} points_t;

points_t points_default();

errors_t allocate_points(points_t &points);

errors_t free_points(points_t &points);

errors_t read_inf_about_points(points_t &points, FILE *fin);

errors_t read_amount_points(points_t &points, FILE *fin);

errors_t read_points(points_t &points, FILE *fin);

errors_t move_points(points_t &points, const move_t &coeff);

errors_t rotate_points(points_t &points, const point_t &r_center, const rotate_t &coeff);

errors_t scale_points(points_t &points, const point_t &s_center, const scale_t &coeff);

errors_t save_points(const points_t &points, FILE *fout);

#endif // POINTS_H
