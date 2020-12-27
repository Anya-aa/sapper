#include "gamemsg.h"
#include "maingame.h"
#include <QFont>
#include <QDebug>
#include <QKeyEvent>

extern Game * game;

GameMsg::GameMsg(): QGraphicsItemGroup (), QObject ()
{
    setlocale(LC_ALL, "Russian");
    msg1 = new QGraphicsTextItem();
    msg1->setFont(QFont("Аркада", 18));
    msg1->setPlainText(QString("Игра окончена"));
    msg1->setDefaultTextColor(Qt::white);
    msg1->setZValue(1);
    msg1->setPos(game->scene->width()/2 - msg1->boundingRect().width()/2,  250);

    msg2 = new QGraphicsTextItem();
    msg2->setFont(QFont("Аркада", 18));
    msg2->setPlainText(QString("Нажмите пробел для начала"));
    msg2->setDefaultTextColor(Qt::white);
    msg2->setZValue(1);
    msg2->setPos(game->scene->width()/2 - msg2->boundingRect().width()/2,  325);

    addToGroup(msg1);
    addToGroup(msg2);

}

void GameMsg::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space){
        game->resetGame();
    }
}
