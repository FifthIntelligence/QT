#include "playscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QLabel>
#include "mycoin.h"
#include <QGraphicsOpacityEffect>
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QSoundEffect>

PlayScene::PlayScene(QWidget *parent)
    : QMainWindow{parent}
{


}

PlayScene::PlayScene(int levelNum)
{
    QString str = QString("you have entered %1 level").arg(levelNum);
    qDebug() << str;
    this->levelIndex = levelNum;

    // set the common things of playscene
    this->setFixedSize(960, 540);   // set the window's size
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("paly the game scene");
    QMenuBar *bar = menuBar();      // create menubar
    setMenuBar(bar);        // put the menubar to current window
    QMenu *startMenu = bar->addMenu("Start");
    QAction * quitAction = startMenu->addAction("Exit");
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    // prepare the button audio
    QSoundEffect *coinSound = new QSoundEffect(this);
    coinSound->setSource(QUrl::fromLocalFile(":/res/ConFlipSound.WAV"));
    coinSound->setVolume(0.3);
    QSoundEffect *winSound = new QSoundEffect(this);
    winSound->setSource(QUrl::fromLocalFile(":/res/LevelWinSound.WAV"));
    winSound->setVolume(0.3);


    // set the back button
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() - 40, this->height() - backBtn->height() - 20);
    connect(backBtn, &MyPushButton::clicked, [=](){
        emit this->chooseSceneBack();
//        qDebug() << "In play scene, have clicked the back button";
    });

    // show the current game level
    QLabel * label = new QLabel;
    label->setParent(this);
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::white); // set font color to white
    label->setPalette(palette);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str_1 = QString("Leavel: %1").arg(this->levelIndex);
    label->setText(str_1);
    label->setGeometry(QRect(30, this->height() - 50, 150, 50));

    // initialize the two dimensional array data
    dataConfig config;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    // create vectory picture
    QLabel* winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelComPletedDialogBg.png");
    winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move((this->width() - tmpPix.width())*0.5, -tmpPix.height());

    // create coin background
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            // create coin background
            QPixmap pix = QPixmap(":/res/BoardNode.png");
            pix = pix.scaled(pix.width()*1.5, pix.height()*1.5);
            QLabel *label = new QLabel;
            label->setGeometry(0, 0, pix.width(), pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(330 + i*85, 170 + j*85);
            QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect();  // set label opacity
            effect->setOpacity(0.6);
            label->setGraphicsEffect(effect);

            // create the coin
            QString str;
            if(this->gameArray[i][j] == 1){
                str = ":/res/Coin0001.png";
            }else{
                str = ":/res/Coin0008.png";
            }
            MyCoin *coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(331.5 + i*85, 171.5 + j*85);
            coin->posX = i;    // record x coordinate
            coin->posY = j;     // record y coordinate
            coin->flag = gameArray[i][j];       // record the front and back flag

            coinBtn[i][j] = coin;       // save the coin information

            connect(coin, &MyCoin::clicked, [=](){      // set can't click on the other coins uitil the animation has finished
                for(int i = 0; i < 4; ++i){
                    for(int j = 0; j < 4; ++j){
                        this->coinBtn[i][j]->isWin = true;
                    }
                }
            });

            // monitor the goid coins whitch is fliping
            connect(coin, &MyCoin::clicked,[=](){
                coinSound->play();
                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;

                QTimer::singleShot(300, this, [=](){
                    // flip the right
                    if(coin->posX + 1 <= 3){
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY] == 0 ? 1 : 0;
                    }
                    // flip the left
                    if(coin->posX - 1 >= 0){
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY] == 0 ? 1 : 0;
                    }
                    // flip the top
                    if(coin->posY + 1 <= 3){
                        coinBtn[coin->posX][coin->posY + 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY + 1] = this->gameArray[coin->posX][coin->posY + 1] == 0 ? 1 : 0;
                    }
                    // flip the bottom
                    if(coin->posY - 1 >= 0){
                        coinBtn[coin->posX][coin->posY - 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY - 1] = this->gameArray[coin->posX][coin->posY - 1] == 0 ? 1 : 0;
                    }


                    for(int i = 0; i < 4; ++i){
                        for(int j = 0; j < 4; ++j){
                            this->coinBtn[i][j]->isWin = false;
                        }
                    };

                    // judge weather the game have win
                    this->isWin = true;
                    for(int i = 0; i < 4; ++i){
                        for(int j = 0; j < 4; ++j){
                            if(coinBtn[i][j]->flag == false){
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    if(this->isWin == true){
                        qDebug() << "You have win this level";
                        winSound->play();
                        for(int i = 0; i < 4; ++i){
                            for(int j = 0; j < 4; ++j){
                                coinBtn[i][j]->isWin = true;
                            }
                        }
                        // move the picture of victory down
                        QPropertyAnimation * animation = new QPropertyAnimation(winLabel, "geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
                        animation->setEndValue(QRect(winLabel->x(), winLabel->y() + 180, winLabel->width(), winLabel->height()));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                    }

                });
            });
        }
    }



}

// draw the backgroung image
void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix{};
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);       // draw the background inmage
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.8, pix.height()*0.8);        // scale the title picture
    painter.drawPixmap((this->width()  - pix.width())*0.5, 30, pix.width(), pix.height(), pix);
}
