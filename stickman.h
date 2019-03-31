#ifndef STICKMAN_H
#define STICKMAN_H

#include <QString>
#include <QPainter>
#include <draw_ob.h>

class stickman: public draw_ob
{
public:
    stickman();
    void renderStickman(QPainter &painter);
    void setSize(QString size);
    QString showSize();

private:
    QString size;
};

#endif // STICKMAN_H
