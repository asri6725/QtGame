#ifndef DRAW_OB_H
#define DRAW_OB_H

class draw_ob
{
public:
    draw_ob();
    void move();
    void set_x_speed(int x_speed);
    void set_x_pos(int x_pos);
    void set_y_pos(int y_pos);

    int get_x_speed();
    int get_x_pos();
    int get_y_pos();

private:
    int x_speed;
    int x_pos;
    int y_pos;
};

#endif // DRAW_OB_H
