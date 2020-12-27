#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <QObject>
#include <QGraphicsPixmapItem>


class GameObj:public QObject, public QGraphicsPixmapItem
{
public:
    GameObj();
};

#endif // GAMEOBJ_H
