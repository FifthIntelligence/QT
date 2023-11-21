#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include "ChooseLevelScene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainscene; }
QT_END_NAMESPACE

class mainscene : public QMainWindow
{
    Q_OBJECT

public:
    mainscene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *); // override paintEvent event, to draw background picture
    ~mainscene();

private:
    Ui::mainscene *ui;
    ChooseLevelScene *chooseScene = nullptr;

};
#endif // MAINSCENE_H
