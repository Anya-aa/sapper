#ifndef PLAYER_H
#define PLAYER_H

#include "gameobj.h"
#include <QSet>
#include <QTime>
#include <QTimer>

class Player: public GameObj
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    QSet<int> pressedKeys;
    int shootDelayMS;
    QTime nextFire;
    QTimer * powerUpTimer;
    int powerUpLevel;
public slots:
    void performAction();
    void performMovement();
    void powerUp();
    void powerDown();

};

#endif // PLAYER_H
