#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QPainter>
#include <stickman.h>
#include <back_img.h>
#include <QTimer>
#include <read.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void readfile();
    void setValues();
    ~Dialog();

public slots:
    void nextFrame();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;
    back_img bg;
    stickman man;
    QVariantMap json;
};

#endif // DIALOG_H
