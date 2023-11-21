#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString btnImg);

    int posX{};     // x-coordinate
    int posY{};     // y-coordinate
    bool flag{};    // the front and back signs
    QTimer *timer1;      // front to back
    QTimer *timer2;      // back to front
    int min = 1;    // the minimum picture number
    int max = 8;    // the maximum picture number

    void changeFlag();      // toggle flag

    bool isAnimation = false;   // the signal of animation

    void mousePressEvent(QMouseEvent *e);

    bool isWin = false;
private:

signals:

};

#endif // MYCOIN_H
