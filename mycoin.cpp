#include "mycoin.h"

MyCoin::MyCoin(QWidget *parent)
    : QPushButton{parent}
{

}

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret){
        QString str = QString("Picture %1 load filed").arg(btnImg);
        qDebug() << str;
        return;
    }
    pix = pix.scaled(pix.width()*0.3, pix.height()*0.3);
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    // initializa the timer
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    // monitor head to tails
    connect(timer1, &QTimer::timeout,[=](){
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pixmap.load(str);
        pixmap = pixmap.scaled(pixmap.width()*0.3, pixmap.height()*0.3);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        if(this->min > this->max){
            this->min = 1;
            isAnimation = false;
            timer1->stop();
        }
    });

    // monitor tails to head
    connect(timer2, &QTimer::timeout,[=](){
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pixmap.load(str);
        pixmap = pixmap.scaled(pixmap.width()*0.3, pixmap.height()*0.3);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        if(this->max < this->min){
            this->max = 8;
            isAnimation = false;
            timer2->stop();
        }
    });

}

void MyCoin::changeFlag()
{
    if(this->flag){
        timer1->start(30);
        isAnimation = true;
        this->flag = false;
    }else{
        timer2->start(30);
        isAnimation = true;
        this->flag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->isWin){
        return;
    }else{
        QPushButton::mousePressEvent(e);    // leave it to his father to deal with
    }
}
