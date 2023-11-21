#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);
    void paintEvent(QPaintEvent *);
private:
    int levelIndex;     // internal member variable, to record the level choosed
    int gameArray[4][4]{};  // two dimensional array data

    MyCoin * coinBtn[4][4]{};

    bool isWin;     // judge weather the level is win
signals:
    void chooseSceneBack();

};

#endif // PLAYSCENE_H
