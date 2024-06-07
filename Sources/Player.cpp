/********************************************************
 * Player                                                *
 *      A file implementing a simple player  class       *
 ********************************************************/

#include<QKeyEvent>
#include<QGraphicsScene>
#include"Player.h"
#include"Patronus.h"
#include"dementor.h"
#include"game.h"

extern Game* HogwartsGame;
/********************************************************
 * Player::Player -- Constructor                        *
 ********************************************************/
Player::Player(QGraphicsItem* parent):QGraphicsPixmapItem(parent){

    // load player image
    QPixmap playerImage(":/images/harry.png");

    // scale image
    setPixmap(playerImage);
}


void Player::keyPressEvent(QKeyEvent* event)
{

    if(event->key() == Qt::Key_Left) // check if the left key was pressed
    {
        // move the player to the left
        if(pos().x()>0)
        {setPos(x()-10,y());}
    }
    else if(event->key() == Qt::Key_Right) // check if the right key was pressed
    {
        // move the player to the right
        if(pos().x()+100<scene()->width())
        {setPos(x()+10,y());}
    }
    else if(event->key() == Qt::Key_Up) // check if the up key was pressed
    {
        // move player up
        if(pos().y()+100>0)
        {setPos(x(),y()-10);}
    }
    else if(event->key() == Qt::Key_Space) // check if the space key was pressed
    {
        // create patronus item
        Patronus* playerPatronus = new Patronus();
        // set patronus item position in the scene
        playerPatronus->setPos(x(),y());

        // add the patronus item to the scene
        scene()->addItem(playerPatronus);

    }
}

void Player::spawn()
{
    Dementor* dementor = nullptr;
    if(0 < HogwartsGame->getGamePlayerHealth()->getPlayerHealth() && Max_Game_Score != HogwartsGame->getGameScore()->getScore())
    {
        // create dementor item
        dementor =new Dementor();
        // add the dementor item to the scene
        scene()->addItem(dementor);
    }

}

