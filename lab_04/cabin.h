#ifndef CABIN_H
#define CABIN_H

#include <QObject>

#include "constants.h"

#include "doors.h"

class Cabin : public QObject
{
Q_OBJECT
    explicit Cabin(QObject *parent = nullptr);
    enum State { MOVE, STOPPED, LOCKED, UNLOCKED, PREPARE };

signals:
    void cabin_unlocked();
    void doors_to_open();
    void cabin_floor_passed();

public slots:
    void cabin_lock();
    void cabin_unlock();
    void cabin_prepare(Direction direct);
    void cabin_move(Direction direct);
    void cabin_stop();

private:
    friend class Elevator;
    QTimer floor_pass;
    State state;
    Doors doors;
};

#endif // CABIN_H
