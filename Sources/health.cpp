/********************************************************
 * Health.cpp                                           *
 *      A file implementing a simple health class       *
 ********************************************************/

#include "health.h"
#include"main.h"
#include<QFont>



Health::Health(QGraphicsTextItem* parent): QGraphicsTextItem(parent) {

    playerHealth = 3;
    SetCustomerFont(this,":/fonts/harryFont.ttf",30);
    setPlainText(QString("Player Health: ")+ QString::number(playerHealth));
    setDefaultTextColor(Qt::darkRed);
}



void Health::decresePlayerHealth()
{
    if(--playerHealth >=0)
    {
        setPlainText(QString("Player Health: ")+ QString::number(playerHealth));
    }
}
int Health::getPlayerHealth() const noexcept
{
    return playerHealth;
}

void Health::setHealth() noexcept{
    playerHealth = 0;
}
