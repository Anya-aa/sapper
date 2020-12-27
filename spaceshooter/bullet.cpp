#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include "maingame.h"

extern Game * game;

Bullet::Bullet(): GameObj ()
{

    setPixmap(QPixmap(":/images/bullet.png"));


    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void Bullet::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size(); ++i){
        auto tempPtr = colliding_items[i];
        if(typeid(*tempPtr) == typeid(Enemy)){

            game->score->increase();

            connect(this, SIGNAL(enemyDefeated(int)), static_cast<Enemy*>(colliding_items[i]), SLOT(spawnPowerUp(int)));
            emit enemyDefeated(game->score->getScore());

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            static_cast<GameObj*>(colliding_items[i])->deleteLater();
            this->deleteLater();
            return;
        }

    }

    setPos(x(), y()-20);
    if(pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        this->deleteLater();
    }
}
