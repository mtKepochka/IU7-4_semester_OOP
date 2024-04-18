#ifndef ACTIONS_DATA_H
#define ACTIONS_DATA_H

typedef struct
{
    double dx;
    double dy;
    double dz;
} move_t;

typedef struct
{
    double ax;
    double ay;
    double az;
} rotate_t;

typedef struct
{
    double kx;
    double ky;
    double kz;
} scale_t;

#endif // ACTIONS_DATA_H
