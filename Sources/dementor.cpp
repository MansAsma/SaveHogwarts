#include<QTimer>
#include<QGraphicsScene>
#include<QDebug>
#include <Qlist>
#include <stdlib.h>
#include "dementor.h"
#include"Player.h"
#include"game.h"
#include"health.h"
extern Game* HogwartsGame;


Dementor::Dementor(QGraphicsItem* parent):QGraphicsPixmapItem(parent) {

    // get random x position for the dementor
    int xRandPosition = rand()% 700;

    // set the position x_pos = xRandPosition , y_pos = 0
    setPos(xRandPosition,0);

    //Load dementor item image
    QPixmap dementorImage(":/images/dementor.png");
    setPixmap(dementorImage);
    setTransformOriginPoint(50,50);

    timer = new QTimer();
    // every t= timer the dementor will move
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // set the timer to 40 ms
    timer->start(40);
}

void Dementor::move()
{

    // flag to check if the dementor item was deleted or not
    bool isDeleted = false;

    //move the Dementor down
    setPos(x(),y()+5);

    // get list of items collided with the dementor item
    QList<QGraphicsItem*> collidingItem = collidingItems();

    for(int index=0; index < collidingItem.size();++index)
    {
        // check if the item collided is a player item
        if(typeid(*(collidingItem[index])) == typeid(Player))
        {
            // decrease the health of the player
            HogwartsGame->getGamePlayerHealth()->decresePlayerHealth();

            delete this;
            isDeleted =true;

        }
        if( 0 == HogwartsGame->getGamePlayerHealth()->getPlayerHealth())
        {
            HogwartsGame ->gameIsOver =true;
            return;
        }
    }
    if(!isDeleted && (pos().y()> scene()->height()))
    {
         HogwartsGame ->gameIsOver =true;
        delete this;
    }

}

Dementor::~Dementor()
{
    delete timer;
}

