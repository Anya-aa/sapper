#ifndef MAINGAME_H
#define MAINGAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include "score.h"
#include "health.h"
#include "enemy.h"
#include "bullet.h"
#include "gamemsg.h"
#include "powerup.h"


class Game : public QGraphicsView
{
    Q_OBJECT

public:

    Game(QWidget * parent=nullptr);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Score * highScoreText;
    Health * playerHealth;
    QTimer * enemyTimer;
    QTimer * actionTimer;
    QTimer * movementTimer;
    bool gameRunning;
    void endGame();
    void resetGame();

private:
    GameMsg * gameOverMsg;
    int highScore = 0;
    int enemyCounter;
    int wave;
    double enemySpeed = 4.0;
    void drawWindow();
    void runGame();
    void drawGameOverMsg();
public slots:
    void spawn();
};

#endif // MAINGAME_H
