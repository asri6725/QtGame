#ifndef BACK_IMG_H
#define BACK_IMG_H

#include <QString>
#include <QPainter>
#include <draw_ob.h>

class back_img : public draw_ob
{
public:
    back_img();
    void renderBackImg(QPainter &painter, int ht);
    void setImg(QString img);
    QString showImg();

private:
    QString img;
};

#endif // BACK_IMG_H
