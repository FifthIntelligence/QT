#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include <QPixmap>
#include "mypushbutton.h"
#include <qDebug>
#include <QTimer>
#include <QLabel>
#include <QSoundEffect>



ChooseLevelScene::ChooseLevelScene(QMainWindow *parent)
    : QMainWindow{parent}
{
    // set the common things of chooselebelscene
    this->setFixedSize(960, 540);   // set the window's size
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("Choose The Level Scene");
    QMenuBar *bar = menuBar();      // create menubar
    setMenuBar(bar);        // put the menubar to current window
    QMenu *startMenu = bar->addMenu("Start");
    QAction * quitAction = startMenu->addAction("Exit");
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    // prepare the button audio
    QSoundEffect *chooseSound = new QSoundEffect(this);
    chooseSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.WAV"));
    chooseSound->setVolume(0.3);
    QSoundEffect *backSound = new QSoundEffect(this);
    backSound->setSource(QUrl::fromLocalFile(":/res/BackButtonSound.WAV"));
    backSound->setVolume(0.3);

    // set the back button
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() - 40, this->height() - backBtn->height() - 20);
    connect(backBtn, &MyPushButton::clicked, [=](){
        backSound->play();
        //emit this->chooseSceneBack();       // release the signal to back mainsecne
        emit this->chooseSceneBack();

    });

    // create buttons to choose level
    for(int i = 0; i < 20; ++i){

        // cteate buttons' background
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(100 + i%10*80, 200 + i/10*80);    // use one circle to make a matrix

        // monitor each pushbutton's clicked event
        connect(menuBtn, &MyPushButton::clicked,[=](){
            QString str = QString("You have choosed %1 level").arg(i + 1);
            chooseSound->play();
            qDebug() << str;

            // enter the playscene
            this->hide();
            play = new PlayScene(i + 1);
            play->setGeometry(this->geometry());
            play->show();   // show this scene

            connect(play, &PlayScene::chooseSceneBack,[=](){
                backSound->play();
                this->show();
                delete play;
                play = nullptr;
            });
        });

        // create label
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i + 1));
        label->move(100 + i%10*80, 200 + i/10*80);
        label->setAlignment(Qt::AlignCenter);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);  // set mouse penetration


    }// create buttons to choose level

}

// draw background image
void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix{};
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);       // draw the background inmage

    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.8, pix.height()*0.8);        // scale the title picture
    painter.drawPixmap((this->width()  - pix.width())*0.5, 30, pix.width(), pix.height(), pix);

}
