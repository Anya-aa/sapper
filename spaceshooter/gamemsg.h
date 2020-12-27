#ifndef GAMEMSG_H
#define GAMEMSG_H

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QSet>

class GameMsg: public QGraphicsItemGroup, public QObject
{
public:
    GameMsg();
private:
    QGraphicsPixmapItem * msgBox;
    QGraphicsTextItem * msg1;
    QGraphicsTextItem * msg2;

    void keyPressEvent(QKeyEvent * event);



};

#endif // GAMEMSG_H
