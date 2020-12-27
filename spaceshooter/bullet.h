#ifndef BULLET_H
#define BULLET_H

#include "gameobj.h"

class Bullet : public GameObj
{
    Q_OBJECT

public:
    Bullet();
signals:
    void enemyDefeated(int totalKills);
public slots:
    void move();
};

#endif // BULLET_H
