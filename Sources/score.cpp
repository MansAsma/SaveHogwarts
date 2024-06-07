#include<QFont>
#include <QFontDatabase>
#include "score.h"
#include"main.h"

Score::Score(QGraphicsTextItem* parent): QGraphicsTextItem(parent)
{
    score = 0;
    SetCustomerFont(this,":/fonts/harryFont.ttf",30);
    setPlainText(QString("Score: ")+ QString::number(score));
    setDefaultTextColor(Qt::black);
}


void Score::increseScore()
{
    ++score;
     setPlainText(QString("Score: ")+ QString::number(score));
}

int Score::getScore() const noexcept{
    return score;
}
