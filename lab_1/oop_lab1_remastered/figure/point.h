#ifndef POINT_H
#define POINT_H

#include <cmath>

#include "actions_data.h"
#include "errors.h"

typedef struct
{
    double x;
    double y;
    double z;
} point_t;

point_t point_default();

errors_t read_point(point_t &point, FILE *fin);

errors_t move_point(point_t &point, const move_t &move);

errors_t rotate_point(point_t &point, const point_t &r_center, const rotate_t &rotate);

errors_t scale_point(point_t &point, const point_t &s_center, const scale_t &scale);

errors_t save_point(const point_t &point, FILE *fout);

#endif // POINT_H
