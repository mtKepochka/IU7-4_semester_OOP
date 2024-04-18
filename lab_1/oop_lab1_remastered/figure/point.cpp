#include "point.h"

inline double to_radians(const double &angle) {
    return angle * (M_PI / 180);
}

static errors_t rotate_xp(point_t &point, const double angle)
{
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double y = point.y;

    point.y = point.y * r_cos + point.z * r_sin;
    point.z = -y * r_sin + point.z * r_cos;
    return SUCCESS;
}

static errors_t rotate_yp(point_t &point, const double angle)
{
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double x = point.x;

    point.x = point.x * r_cos + point.z * r_sin;
    point.z = -x * r_sin + point.z * r_cos;
    return SUCCESS;
}

static errors_t rotate_zp(point_t &point, const double angle)
{
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double x = point.x;

    point.x = point.x * r_cos + point.y * r_sin;
    point.y = -x * r_sin + point.y * r_cos;
    return SUCCESS;
}

point_t point_default()
{
    return point_t{0.0, 0.0, 0.0};
}

errors_t read_point(point_t &point, FILE *fin)
{
    errors_t rc = SUCCESS;
    if (fin == NULL)
        rc = FILE_OPEN_ERROR;
    else if(fscanf(fin, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
        rc = READ_FILE_ERROR;

    return rc;
}

errors_t move_point(point_t &point, const move_t &move)
{
    point.x += move.dx;
    point.y += move.dy;
    point.z += move.dz;
    return SUCCESS;
}

errors_t move_to_local_center(point_t &point, const point_t &r_center)
{
    move_t to_local = {
        .dx = -r_center.x,
        .dy = -r_center.y,
        .dz = -r_center.z
    };
    move_point(point, to_local);
    return SUCCESS;
}

errors_t move_to_global_center(point_t &point, const point_t &r_center)
{
    move_t to_global = {
        .dx = r_center.x,
        .dy = r_center.y,
        .dz = r_center.z
    };
    move_point(point, to_global);
    return SUCCESS;
}

errors_t rotate_point(point_t &point, const point_t &r_center, const rotate_t &rotate)
{
    move_to_local_center(point, r_center);
    rotate_xp(point, rotate.ax);
    rotate_yp(point, rotate.ay);
    rotate_zp(point, rotate.az);
    move_to_global_center(point, r_center);
    return SUCCESS;
}

errors_t scale_point(point_t &point, const point_t &s_center, const scale_t &scale)
{
    point.x = (point.x - s_center.x) * scale.kx + s_center.x;
    point.y = (point.y - s_center.y) * scale.ky + s_center.y;
    point.z = (point.z - s_center.z) * scale.kz + s_center.z;
    return SUCCESS;
}

errors_t save_point(const point_t &point, FILE *fout)
{
    int rc = fprintf(fout, "%lf %lf %lf\n", point.x,
                     point.y,
                     point.z);
    if (rc < 0)
        return FILE_WRITE_ERROR;
    return SUCCESS;
}
