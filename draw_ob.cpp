#include "draw_ob.h"

draw_ob::draw_ob()
{
    this->x_speed = 0;
    this->x_pos = 0;
    this->y_pos = 0;
}

void draw_ob::set_x_speed(int x_speed)
{
    this->x_speed = x_speed;
}

void draw_ob::set_x_pos(int x_pos)
{
    this->x_pos = x_pos;
}

void draw_ob::set_y_pos(int y_pos)
{
    this->y_pos = y_pos;
}

int draw_ob::get_x_speed()
{
    return this->x_speed;
}

int draw_ob::get_x_pos()
{
    return this->x_pos;
}

int draw_ob::get_y_pos()
{
    return this->y_pos;
}
