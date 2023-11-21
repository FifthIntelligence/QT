#include "mypushbutton.h"
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QPushButton *parent)
    : QPushButton{parent}
{

}

MyPushButton::MyPushButton(QString normalImag, QString pressImg)
{
    normalImagePath = normalImag;
    pressImagePath = pressImg;

    QPixmap pixmap;
    if(!pixmap.load(normalImagePath)){      // load the picture
        qDebug() << "load the picture filed";
        return;
    }

    this->setFixedSize(pixmap.width(), pixmap.height());        // give the pushbotton a fixed size
    this->setStyleSheet("QPushButton{border:0px;}");        // set the pushbutton's style(irregular picture)
    this->setIcon(pixmap);      // set the picture
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));      // set the picture's size
}

void MyPushButton::zoom1()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");      // create animation objetc
    animation->setDuration(200);    // set animation time interval
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));       // set satrt position
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));     // set end position
    animation->setEasingCurve(QEasingCurve::OutBounce);     // set transation curve
    animation->start();
}

void MyPushButton::zoom2()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");      // create animation objetc
    animation->setDuration(200);    // set animation time interval
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));       // set satrt position
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));     // set end position
    animation->setEasingCurve(QEasingCurve::OutBounce);     // set transation curve
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImagePath != ""){     // determine weather a pressed image is passed in

        QPixmap pixmap;
        bool ret = pixmap.load(this->pressImagePath);
        if(!ret){      // load the picture
            qDebug() << "load the picture filed";
            return;
        }
        this->setFixedSize(pixmap.width(), pixmap.height());        // give the pushbotton a fixed size
        this->setStyleSheet("QPushButton{border:0px;}");        // set the pushbutton's style(irregular picture)
        this->setIcon(pixmap);      // set the picture
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));      // set the picture's size
    }
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImagePath != ""){     // determine weather a pressed image is passed in
        QPixmap pixmap;
        bool ret = pixmap.load(this->normalImagePath);
        if(!ret){      // load the picture
            qDebug() << "load the picture filed";
            return;
        }
        this->setFixedSize(pixmap.width(), pixmap.height());        // give the pushbotton a fixed size
        this->setStyleSheet("QPushButton{border:0px;}");        // set the pushbutton's style(irregular picture)
        this->setIcon(pixmap);      // set the picture
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));      // set the picture's size
    }
    return QPushButton::mouseReleaseEvent(e);
}
