#include <QApplication>
#include <QFontDatabase>
#include "maingame.h"
#include <QDebug>





Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();



    return a.exec();
}

