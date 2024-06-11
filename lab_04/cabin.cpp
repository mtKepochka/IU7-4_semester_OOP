#include "cabin.h"

Cabin::Cabin(QObject *parent) : QObject(parent), state(UNLOCKED)
{
    floor_pass.setSingleShot(true);

    QObject::connect(this, SIGNAL(doors_to_open()), &this->doors, SLOT(door_opening()));
    QObject::connect(&this->doors, SIGNAL(closed()), this, SLOT(cabin_unlock()));
}

void Cabin::cabin_move(Direction direct)
{
    if (this->state != PREPARE && this->state != MOVE)
    {
        return;
    }
    if (this->state == PREPARE)
    {
        this->state = MOVE;
    }
    qDebug() << "Кабина двигается(1 - вверх, 0 - стоит, -1 - вниз)" << direct;
    this->floor_pass.start(FLOOR_PASS_TIME);
}

void Cabin::cabin_stop()
{
    if (this->state != MOVE)
    {
        return;
    }
    this->state = STOPPED;
    qDebug() << "Кабина остановилась.";
    emit cabin_lock();
}

void Cabin::cabin_prepare(Direction direct)
{
    if (this->state != UNLOCKED)
    {
        return;
    }
    this->state = PREPARE;
    qDebug() << "Кабина готовится к движению.";
    emit cabin_move(direct);
}

void Cabin::cabin_lock()
{
    if (this->state != STOPPED)
    {
        return;
    }
    this->state = LOCKED;
    qDebug() << "Кабина заблокировала движение.";
    emit doors_to_open();
}

void Cabin::cabin_unlock()
{
    if (this->state != LOCKED)
    {
        return;
    }

    this->state = UNLOCKED;
    qDebug() << "Кабина разблокировала движение.";

    emit cabin_unlocked();
}












