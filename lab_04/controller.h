#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "constants.h"

class Controller : public QObject
{
Q_OBJECT
    enum PanelState { FREE, MOVE, REACHED_TARGET, UPDATE_TARGET };
public:
    explicit Controller(QObject *parent = nullptr);
    void new_target(int floor);

signals:
    void cabin_to_stop();
    void cabin_doors_to_open();
    void cabin_to_prepare(Direction direct);
    void cabin_to_go_on(Direction direct);

public slots:
    void update_target();
    void handle_move();
    void handle_free();
    void reached_target_floor();
    // void temporal_target();

private:
    int curr_floor = START_FLOOR;
    int main_target = NO_TARGET;
    bool is_temporal_stop = false;

    std::vector<bool> need_to_visit;

    PanelState state;
    Direction direction;

    int find_nearest_main_target();
    Direction find_direction() const;
};

#endif // CONTROLLER_H
