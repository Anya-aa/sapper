#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem (parent)
{
    setlocale(LC_ALL, "Russian");
    score = 0;
    text = QString("Счет: ");


    setPlainText(text + QString::number(score));
    setDefaultTextColor(Qt::darkYellow);
    setFont(QFont("ArcadeClassic", 20));
    setZValue(1);

}

void Score::increase()
{
    score++;
    setPlainText(text + QString::number(score));
}

int Score::getScore()
{
    return score;
}

void Score::setScore(int newScore)
{
    score = newScore;
    setPlainText(text + QString::number(score));
}

void Score::setText(QString newText)
{
    text = newText;
    setPlainText(text + QString::number(score));
}
