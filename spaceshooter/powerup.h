#ifndef POWER_H
#define POWER_H
#include "gameobj.h"

class Power : public GameObj
{
    Q_OBJECT

public:
    Power();
    ~Power();
public slots:
    void move();
};

#endif // POWER_H
