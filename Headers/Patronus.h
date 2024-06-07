#ifndef PATRONUS_H
#define PATRONUS_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Patronus :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Patronus(QGraphicsItem* parent=nullptr);
    ~Patronus();
public slots:
    void move();
private:
    QTimer* timer =nullptr;
};

#endif // PATRONUS_H
