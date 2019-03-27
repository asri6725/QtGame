#ifndef DIALOG_H
#define DIALOG_H
#include <QTimer>
#include <QDialog>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);

    ~Dialog();
public slots:
    void myfunction();

protected:
    void paintEvent(QPaintEvent *event);


private:
    Ui::Dialog *ui;
    int bg_x;
    QTimer *timer;
};

#endif // DIALOG_H
