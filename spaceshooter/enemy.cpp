#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "maingame.h"
#include <QList>
#include "powerup.h"

extern Game * game;

Enemy::Enemy(): GameObj ()
{

    setPixmap(QPixmap(":/images/enemy.png"));

    int random_num = rand() % static_cast<int>(game->scene->width() - pixmap().width());
    setPos(random_num, 0);
    moveSpeed = 5.0;
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
}


Enemy::Enemy(double x, double y, double speed) : GameObj ()
{
    setPixmap(QPixmap(":/images/enemy.png"));
    setPos(x,y);
    moveSpeed = speed;
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
}

Enemy::~Enemy(){
}
void Enemy::move(){

    setPos(x(), y() + moveSpeed);
    if(y() > game->scene->height()){
        scene()->removeItem(this);
        this->deleteLater();
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach(QGraphicsItem* gItem, colliding_items){
        if(typeid(*gItem) == typeid(Player)){
            game->playerHealth->decrease();
            if(game->playerHealth->getHealth() != 0){
                scene()->removeItem(this);
                this->deleteLater();
            }

        }
    }
}

void Enemy::spawnPowerUp(int totalKills){
    if(totalKills % 5 == 0){
        Power * powerUp = new Power();
        powerUp->setPos(x() + pixmap().width()/2, y());
        scene()->addItem(powerUp);
    }
}
