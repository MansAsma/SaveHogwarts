#include "Patronus.h"
#include"dementor.h"
#include"game.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QDebug>
#include <Qlist>

extern Game* HogwartsGame;

Patronus::Patronus(QGraphicsItem* parent):QGraphicsPixmapItem(parent) {

    QPixmap patronusImage(":/images/Patronus.png"); // load image
    setPixmap(patronusImage.scaled(100,100)); // scale image width =100 and height =100

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move())); // every 50ms the Patronus will move
    timer->start(50); // set the timer to 50 ms
}

void Patronus::move()
{
    QList<QGraphicsItem*> collidingItem = collidingItems(); // list of items that collided with the Patronus object
    for(int index=0; index < collidingItem.size();++index)
    {
        // check if the collided item is a dementor
        if(typeid(*(collidingItem[index])) == typeid(Dementor))
        {

            HogwartsGame->getGameScore()->increseScore(); // increase the score game
            scene()->removeItem(collidingItem[index]); // remove the dementor item from the scene
            scene()->removeItem(this); // remove the patronus item from the scene
            //delete
            delete collidingItem[index];
            delete this;
            //clear the list
            collidingItem.clear();
            return;
        }
    }
    //move the Patronus up
    setPos(x(),y()-10);
    if(pos().y() <0)
    {
        scene()->removeItem(this); // remove the patronus item from the scene
        delete this; // delete it
    }

}

Patronus::~Patronus(){

    delete timer;
}
