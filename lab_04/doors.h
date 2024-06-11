#ifndef DOORS_H
#define DOORS_H

#include <QObject>

#include "constants.h"

class Doors : public QObject {
Q_OBJECT
    enum StateDoors { OPENING, CLOSING, OPENED, CLOSED };
public:
    explicit Doors(QObject *parent = nullptr);

signals:
    void closed();
    void opened();

public slots:
    void door_open();
    void door_opening();
    void door_close();
    void door_closing();

private:
    StateDoors state;
    QTimer open_time;
    QTimer close_time;
    QTimer floor_stay_time;
};

#endif // DOORS_H
