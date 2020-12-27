#include "powerup.h"
#include <QTimer>
#include <QList>
#include <QDebug>
#include <QGraphicsScene>
#include "player.h"
#include "maingame.h"

extern Game * game;

Power::Power() : GameObj ()
{
    setPixmap(QPixmap(":/images/powerup.png"));
    QTimer * moveTimer = new QTimer();
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(100);

}
Power::~Power(){

}

void Power::move(){
    setPos(x(), y()+10);

    if(y() > game->scene->height()){
        scene()->removeItem(this);
        this->deleteLater();
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); ++i){
        auto type_ptr = colliding_items[i];
        if(typeid(*type_ptr) == typeid(Player)){
            Player * myPlayerPtr = static_cast<Player*>(colliding_items[i]);
            connect(this, SIGNAL(destroyed()), myPlayerPtr, SLOT(powerUp()));
            scene()->removeItem(this);
            this->deleteLater();
        }
    }
}
