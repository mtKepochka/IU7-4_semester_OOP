#ifndef ERRORS_H
#define ERRORS_H

#include <QMessageBox>

typedef enum
{
    SUCCESS,
    FILE_OPEN_ERROR,
    FILE_EMPTY_ERROR,
    READ_FILE_ERROR,
    FILE_CLOSE_ERROR,
    FILE_WRITE_ERROR,
    FIGURE_NOT_LOADED,
    SIZE_POINTS_ERROR,
    SIZE_EDGES_ERROR,
    SCENE_DRAW_ERROR,
    MEMORY_ALLOCATE_ERROR,
    COEFF_SCALE_ERROR,
    NO_DATA_WRITE_ERROR,
    COMMAND_UNDEFINED
} errors_t;

void error_message(errors_t &error);

#endif // ERRORS_H
