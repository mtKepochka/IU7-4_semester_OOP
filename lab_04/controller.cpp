#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent),
    curr_floor(START_FLOOR), main_target(NO_TARGET),
    need_to_visit(FLOORS_COUNT, false), state(FREE),
    direction(STAY)
{

}

int Controller::find_nearest_main_target()
{
    bool is_target_updated = false;
    int min_distance = FLOORS_COUNT + 1;
    int potential_next_floor = NO_TARGET;

    for (int i = 0; i < this->need_to_visit.size(); i++)
    {
        if(need_to_visit[i])
        {
            int distance = abs(i - this->curr_floor);
            if (distance < min_distance)
            {
                is_target_updated = true;
                min_distance = distance;
                potential_next_floor = i + 1;
            }
        }
    }
    if (is_target_updated)
        return potential_next_floor;
    return -1;
}

void Controller::new_target(const int floor)
{
    if (this->need_to_visit[floor - 1])
        return;
    this->need_to_visit[floor - 1] = true;
    if (this->state == REACHED_TARGET and floor == this->curr_floor)
    {
        this->need_to_visit[floor - 1] = false;
        emit cabin_doors_to_open();
    }
    else if (this->state == FREE)
    {
        emit update_target();
    }
}

void Controller::handle_move()
{
    if (this->state != UPDATE_TARGET && this->state != MOVE)
    {
        return;
    }

    this->state = MOVE;
    this->curr_floor += this->direction;
    qDebug() << "Этаж №" << this->curr_floor << "| Лифт приехал.";

    if (this->curr_floor != this->main_target)
    {
        if (this->need_to_visit[this->curr_floor - 1])
        {
            emit reached_target_floor();
        }
        else
        {
            emit cabin_to_go_on(this->direction);
        }
    }
    else
    {
        emit reached_target_floor();
    }
}

void Controller::handle_free()
{
    if (this->state != UPDATE_TARGET)
        return;

    this->state = FREE;

    qDebug() << "Этаж №" << this->curr_floor << "| Контроллер свободен.";
}

void Controller::reached_target_floor()
{
    if (this->state != MOVE)
        return;
    this->state = REACHED_TARGET;
    this->need_to_visit[this->curr_floor - 1] = false;
    if (this->curr_floor != this->main_target)
        this->is_temporal_stop = true;
    qDebug() << "Этаж №" << this->curr_floor << "| Контроллер понял, что на нужном этаже.";
    emit cabin_to_stop();

}

// void Controller::temporal_target()
// {
//     if (this->state != MOVE)
//         return;

//     this->state = TEMPORAL_TARGET;

//     this->need_to_visit[this->curr_floor - 1] = false;
//     this->is_temporal_stop = true;
//     qDebug() << "Этаж №" << this->curr_floor << "| Контроллер заехал на этаж по дороге.";
//     emit cabin_to_stop();
// }

void Controller::update_target()
{
    if (this->state != FREE && this->state != REACHED_TARGET /*&& this->state != TEMPORAL_TARGET*/)
        return;
    PanelState prevState = this->state;

    this->state = UPDATE_TARGET;

    int next_floor = -1;

    // if (prevState == TEMPORAL_TARGET)
    // {
    //     next_floor = this->main_target;
    // }
    // else
    // {
        qDebug() << "Этаж №" << this->curr_floor << "| Контроллер ищет куда ехать дальше.";
        next_floor = find_nearest_main_target();
    // }

    if (next_floor == -1)
        emit handle_free();
    else
    {
        // if (prevState == TEMPORAL_TARGET)
        // {
        //     qDebug() << "Контроллер продолжает движение на этаж №" << this->main_target;
        //     emit cabin_to_prepare();
        // }
        // else
        // {
        this->main_target = next_floor;
        this->direction = find_direction();
        qDebug() << "Этаж №" << this->curr_floor << "| Контроллер выбрал целью этаж №" << this->main_target;
        emit cabin_to_prepare(this->direction);
        // }
    }
}

Direction Controller::find_direction() const
{
    if (this->main_target == this->curr_floor)
        return STAY;
    else if (this->main_target < this->curr_floor)
        return DOWN;
    return UP;
}
