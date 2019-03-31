/*
 * I will try to use the factory method design pattern :)
 *
 * The most basic class is draw_ob, which can be used to specify the dimensions of different objects that we want to create.
 * The classes stickman and back_img implement the class draw_obj and the dialog class acts as a factory method.
 *
*/

#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
