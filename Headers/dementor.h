#ifndef DEMENTOR_H
#define DEMENTOR_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Dementor:public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    Dementor(QGraphicsItem* parent =nullptr);
    ~Dementor();
public slots:
    void move();

private:
    QTimer* timer =nullptr;
};

#endif // DEMENTOR_H
