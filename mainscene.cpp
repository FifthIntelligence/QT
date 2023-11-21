#include "mainscene.h"
#include "./ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QSoundEffect>

mainscene::mainscene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainscene)
{
    ui->setupUi(this);

    // configure the main scene
    this->setFixedSize(960, 540);   //set fixed window size
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));     //set app picture
    this->setWindowTitle("turn over gold coins");   //set window title

    // achieve exit effect
    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });

    // prepare the start button audio
    QSoundEffect *startSound = new QSoundEffect(this);
    startSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.WAV"));
    startSound->setVolume(0.3);
    QSoundEffect *BGmusic = new QSoundEffect(this);
    BGmusic->setSource(QUrl::fromLocalFile(":/res/BG.WAV"));
    BGmusic->setVolume(0.1);
    BGmusic->play();
    BGmusic->setLoopCount(QSoundEffect::Infinite);

    // draw the start button
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height()*0.8);

    // monitor the action of this button
    chooseScene = new ChooseLevelScene();
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, this, [=](){

        chooseScene->hide();
        this->show();
    });

    connect(startBtn, &MyPushButton::clicked,[=](){
        startSound->play();     // play the audio
        startBtn->zoom1();      // transition down
        startBtn->zoom2();      // transition up
        QTimer::singleShot(50, this, [=](){        // delay 100 ms and show the new window;
            chooseScene->setGeometry(this->geometry());
            this->hide();
            chooseScene->show();
        });
    });
}

void mainscene::paintEvent(QPaintEvent *)
{

    //  draw the background picture
    QPainter painter(this);
    QPixmap pix;
    pix.load( ":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix); // Stretch the image to the length and width of the window

    // draw the title picture
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.8, pix.height()*0.8);        // scale the title picture
    painter.drawPixmap(this->width()*0.5 - pix.width()*0.5, 0, pix);
}

    mainscene::~mainscene()
{
    delete ui;
}
