#include "back_img.h"

back_img::back_img()
{
    this->img = "NULL";
}

void back_img::renderBackImg(QPainter &painter, int ht)
{
    QImage image(img);                                              //load image
    image = image.scaledToHeight(ht, Qt::FastTransformation);      // set constant height

    QRectF target(0.0, 0.0, 1500, ht);
    QRectF source(0.0+this->get_x_pos(), 0.0, image.width(), image.height());

    painter.drawImage(target, image, source);
}

void back_img::setImg(QString img)
{
    this->img = img;
}

QString back_img::showImg()
{
    return this->img;
}

void draw_ob::move(){
    if(this->get_x_pos()>100){
        this->set_x_pos(0);
    }
    this->set_x_pos(this->get_x_pos()+this->get_x_speed());
}
