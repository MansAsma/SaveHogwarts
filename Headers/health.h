#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>

class Health:public QGraphicsTextItem
{
public:
    Health(QGraphicsTextItem* parent =nullptr);
     void decresePlayerHealth();
     int getPlayerHealth() const noexcept;
private:
     int playerHealth;
};

#endif // HEALTH_H
