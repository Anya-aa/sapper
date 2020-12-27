#include "maingame.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QDebug>
#include <QBrush>
#include <QImage>
#include <typeinfo>

Game::Game(QWidget *)
{

    drawWindow();
    runGame();
    show();
}


void Game::drawWindow()
{
    setlocale(LC_ALL, "Russian");
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setStickyFocus(true);
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    player = new Player();

    player->setPos(width()/2 - player->pixmap().width()/2, height() - player->pixmap().height());

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    highScoreText = new Score();
    highScoreText->setText(QString("Рекорд: "));
    scene->addItem(highScoreText);

    score = new Score();
    score->setPos(score->x(), score->y() + 25);
    scene->addItem(score);


    playerHealth = new Health();
    playerHealth->setPos(playerHealth->x(), playerHealth->y() + 50);
    scene->addItem(playerHealth);
}

void Game::runGame()
{
    enemyCounter = 0;
    wave = 0;
    enemyTimer = new QTimer();
    QObject::connect(enemyTimer, SIGNAL(timeout()), this, SLOT(spawn()));
    enemyTimer->start(4000);


    actionTimer = new QTimer();
    QObject::connect(actionTimer, SIGNAL(timeout()), player, SLOT(performAction()));
    actionTimer->start(10);

    movementTimer = new QTimer();
    QObject::connect(movementTimer, SIGNAL(timeout()), player, SLOT(performMovement()));
    movementTimer->start(40);

}

void Game::endGame()
{
    enemyTimer->stop();
    actionTimer->stop();
    movementTimer->stop();
    QList<QGraphicsItem *> sceneItems = items();
    for(int i = 0; i < sceneItems.size(); ++i){
        auto tempPtr = sceneItems[i];


        if( typeid(*tempPtr) == typeid(Enemy)
                || typeid(*tempPtr) == typeid(Bullet) || typeid(*tempPtr) == typeid(Power)
                || typeid(*tempPtr) == typeid(Player)){
            scene->removeItem(sceneItems[i]);
            static_cast<GameObj*>(tempPtr)->deleteLater();
        }

    }
    if(score->getScore() > highScore){
        highScore = score->getScore();
    }
    drawGameOverMsg();

}

void Game::drawGameOverMsg(){
    gameOverMsg = new GameMsg();
    scene->addItem(gameOverMsg);
    gameOverMsg->setFlag(QGraphicsItem::ItemIsFocusable);
    gameOverMsg->setFocus();

}

void Game::resetGame()
{

    scene->removeItem(gameOverMsg);
    gameOverMsg->deleteLater();

    highScoreText->setScore(highScore);

    player = new Player();
    player->setPos(width()/2 - player->pixmap().width()/2, height() - player->pixmap().height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    playerHealth->setHealth(3);
    score->setScore(0);
    wave = 0;
    enemyCounter = 0;
    enemyTimer->start();
    QObject::connect(actionTimer, SIGNAL(timeout()), player, SLOT(performAction()));
    actionTimer->start();
    QObject::connect(movementTimer, SIGNAL(timeout()), player, SLOT(performMovement()));
    movementTimer->start();
}

void Game::spawn()
{

        Enemy * enemy = new Enemy();
        scene->addItem(enemy);
        enemyCounter++;
    qDebug() << "колличество противников : " << enemyCounter;
}
