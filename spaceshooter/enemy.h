#ifndef ENEMY_H
#define ENEMY_H

#include "gameobj.h"

class Enemy:public GameObj
{
    Q_OBJECT

public:
    Enemy();
    Enemy(double x, double y, double speed);
    ~Enemy();
private:
    double moveSpeed;
public slots:
    void move();
    void spawnPowerUp(int totalKills);
};

#endif // ENEMY_H
