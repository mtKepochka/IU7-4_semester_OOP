#include "elevator.h"

Elevator::Elevator()
{
    QObject::connect(&cabin.floor_pass, SIGNAL(timeout()), &controller, SLOT(handle_move()));
    QObject::connect(&cabin, SIGNAL(cabin_unlocked()), &controller, SLOT(update_target()));
    QObject::connect(&controller, SIGNAL(cabin_to_go_on(Direction)), &cabin, SLOT(cabin_move(Direction)));
    QObject::connect(&controller, SIGNAL(cabin_to_prepare(Direction)), &cabin, SLOT(cabin_prepare(Direction)));
    QObject::connect(&controller, SIGNAL(cabin_to_stop()), &cabin, SLOT(cabin_stop()));
    QObject::connect(&controller, SIGNAL(cabin_doors_to_open()), &cabin, SIGNAL(doors_to_open()));
}

void Elevator::btnClick(int btnNumber)
{
    controller.new_target(btnNumber);
}
