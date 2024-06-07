#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score :public QGraphicsTextItem
{
public:
    Score(QGraphicsTextItem* parent =nullptr);
    void increseScore();
    int getScore() const noexcept;
private:
    int score;
};

#endif // SCORE_H
