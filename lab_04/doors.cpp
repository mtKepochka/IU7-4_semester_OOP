#include "doors.h"

Doors::Doors(QObject *parent) : QObject(parent), state(CLOSED)
{
    this->floor_stay_time.setInterval(FLOOR_STAY_TIME);
    this->floor_stay_time.setSingleShot(true);
    this->close_time.setSingleShot(true);
    this->open_time.setSingleShot(true);

    QObject::connect(this, SIGNAL(opened()), &this->floor_stay_time, SLOT(start()));
    QObject::connect(&this->floor_stay_time, SIGNAL(timeout()), this, SLOT(door_closing()));
    QObject::connect(&this->close_time, SIGNAL(timeout()), this, SLOT(door_close()));
    QObject::connect(&this->open_time, SIGNAL(timeout()), this, SLOT(door_open()));
}

void Doors::door_opening()
{
    if (this->state != CLOSED && this->state != CLOSING)
    {
        return;
    }

    StateDoors prevState = this->state;
    this->state = OPENING;

    if (prevState == CLOSED)
    {
        this->state = OPENING;
        this->open_time.start(OPEN_TIME);
    }
    else
    {
        qDebug() << "Прерываю закрытие дверей";

        int remaining_time = this->close_time.remainingTime();
        this->close_time.stop();
        this->open_time.start(OPEN_TIME - remaining_time);
    }

    qDebug() << "Двери открываются";
}

void Doors::door_open()
{
    if (this->state != OPENING)
    {
        return;
    }

    this->state = OPENED;
    qDebug() << "Двери открыты.";
    qDebug() << "Ждем пока все зайдут.";

    emit opened();
}

void Doors::door_closing()
{
    if (this->state != OPENED)
        return;

    this->state = CLOSING;
    this->close_time.start(CLOSE_TIME);
    qDebug() << "Двери закрываются.";
}

void Doors::door_close()
{
    if (this->state != CLOSING)
        return;

    this->state = CLOSED;
    qDebug() << "Двери закрыты.";

    emit closed();
}
