#ifndef ACTIONS_H
#define ACTIONS_H

#include "figure.h"
#include "draw_figure.h"
#include "actions_data.h"
#include "errors.h"

enum action
{
    SAVE,
    OPEN,
    ROTATE,
    MOVE,
    SCALE,
    DRAW,
    QUIT
};

struct request
{
    enum action action;
    union
    {
        const char *filename;
        view_t view;
        rotate_t rotate;
        move_t move;
        scale_t scale;
    };
};

using request_t = struct request;

errors_t manager_actions(request_t &request);

#endif // ACTIONS_H
