#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QMainWindow *parent = nullptr);

private:
    void paintEvent(QPaintEvent *);
    PlayScene * play = NULL;

signals:
    void chooseSceneBack();

};

#endif // CHOOSELEVELSCENE_H
