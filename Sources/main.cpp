/********************************************************
 * main.cpp                                             *
 *         version:    1.0.0 3-06-2024                  *
 ********************************************************/


#include <QApplication>
#include<QTimer>
#include<QObject>
#include <QDialog>
#include<QLabel>
#include <QMessageBox>
#include"game.h"
#include "score.h"
#include"main.h"

/*___________________________ GLOBAL VARIABLES _________________________________*/

Game* HogwartsGame;

/*_____________________________ FUNCTIONS ______________________________________*/


void SetCustomerFont(QGraphicsTextItem* parent,const QString& fileName,int size)
{
    int fontId = QFontDatabase::addApplicationFont(fileName);
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont customFont(fontFamily,size);
    parent->setFont(customFont);
}

void CheckAndQuit() {

    if (HogwartsGame->gameIsOver || Max_Game_Score == HogwartsGame->getGameScore()->getScore()) {
        QMessageBox* widgetMessageBox = new QMessageBox();
        if(HogwartsGame->getGameScore()->getScore() == Max_Game_Score )
        {
            widgetMessageBox->setIconPixmap(QPixmap(":/images/HogwartsIsSaved.png"));
            widgetMessageBox->exec();
        }
        else if(0== HogwartsGame->getGamePlayerHealth()->getPlayerHealth())
        {
            widgetMessageBox->setIconPixmap(QPixmap(":/images/harryDead.png"));
            widgetMessageBox->exec();
        }
        else
        {
            widgetMessageBox->setIconPixmap(QPixmap(":/images/dementorsInHogwarts.png"));
            HogwartsGame->getGamePlayerHealth()->setHealth();
            widgetMessageBox->exec();

        }
        delete widgetMessageBox;
        widgetMessageBox =nullptr;
        delete HogwartsGame;
        HogwartsGame =nullptr;
        QApplication::exit();

    }
}
/********************************************************************************/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    HogwartsGame= new Game();
    HogwartsGame->display();

    QTimer* gameTimer =new QTimer();
    QObject::connect(gameTimer, &QTimer::timeout, &CheckAndQuit);
    gameTimer->start(30);

    return a.exec();
}
