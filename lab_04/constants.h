#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QTimer>
#include <QDebug>

enum Direction {
    DOWN = -1,
    STAY = 0,
    UP = 1
};

#define FLOORS_COUNT 5

#define CLOSE_TIME 1000
#define OPEN_TIME 1000
#define FLOOR_STAY_TIME 2000
#define FLOOR_PASS_TIME 1000

#define START_FLOOR 1
#define NO_TARGET (-1)

#endif // CONSTANTS_H
