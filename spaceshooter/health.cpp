#include "health.h"
#include <QFont>
#include "maingame.h"

extern Game * game;

Health::Health(QGraphicsItem * parent, int desiredHealth): QGraphicsTextItem (parent)
{
    setlocale(LC_ALL, "Russian");
    health = desiredHealth;
    setPlainText(QString("Здоровье: ") + QString::number(health));
    setDefaultTextColor(Qt::darkYellow);
    setFont(QFont("ArcadeClassic", 20));
    setZValue(1);
}

void Health::decrease(){
    health--;
    setPlainText(QString("Здоровье: ") + QString::number(health));
    if(health == 0){
        game->endGame();
    }
}

int Health::getHealth(){
    return health;
}

void Health::setHealth(int newHealth)
{
    health = newHealth;
    setPlainText(QString("Здоровье: ") + QString::number(health));
}
