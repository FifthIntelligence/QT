#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QPushButton *parent = nullptr);
    explicit MyPushButton(QString normalImag, QString pressImg = "");
    void zoom1();   // special effects 1
    void zoom2();   // special effects 2

private:
    QString normalImagePath{};  // save the normal picture path
    QString pressImagePath{};   // save the pressed picture path

    // override button pressed and released events
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

};

#endif // MYPUSHBUTTON_H
