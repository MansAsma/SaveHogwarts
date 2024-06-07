/********************************************************
 * Game                                                 *
 *      A file implementing a simple Game  class        *
 ********************************************************/

#include "game.h"
#include <QBrush>

/********************************************************
 * Game::Game -- Constructor                            *
 ********************************************************/
Game::Game() {
    // create a Scene
    myScene = new QGraphicsScene();
    myScene->setSceneRect(0,0,1000,800); // x=0, y=0, width =800, height =600
    myScene->setBackgroundBrush(QBrush(QImage(":/images/Hogwarts.png")));

    // create player item
    player = new Player();
    // create score item
    gameScore =new Score();
    // create player health item
    playerGameHealth = new Health();

    // add player item to the scene
    myScene->addItem(player);

    // add the game score item to the scene
    myScene->addItem(gameScore);
    // add the player health item to the scene
    myScene->addItem(playerGameHealth);
    // set the position of the player health item in the scene
    playerGameHealth->setPos(0,50);

    // create a view of the scene
    myView = new QGraphicsView(myScene);

    // set the view size : width and height
    myView->setFixedSize(1000,800);

    //set the position of the player in the scene
    player->setPos((myView->width()-100)/2,myView->height()-300);

}

/********************************************************
 * Game::display --                                     *
 * Member function to display the game view             *
 ********************************************************/

void Game::display()
{
    // make the player item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    myView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    myView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    myView->show();
}

/*************************************************************
 * Game::getGamePlayerHealth --                              *
 * Member function to get the player health status           *
 *************************************************************/
Health* Game::getGamePlayerHealth() const noexcept
{
     return playerGameHealth;
 }

/*************************************************************
 * Game::getGameScore --                                     *
 * Member function to get the score of the game              *
 *************************************************************/
Score* Game::getGameScore() const noexcept
{
    return gameScore;
}

/********************************************************
 * Game::Game -- Destructor                            *
 ********************************************************/
Game::~Game()
{
    qDebug()<<"free up memory";
    // free up memory
    delete gameScore;
    delete playerGameHealth;
    delete timer;
    delete player;
    delete myScene;
    delete myView ;
    myScene =nullptr;
    gameScore = nullptr;
    timer =nullptr;
    playerGameHealth = nullptr;
    player =nullptr;
    myView =nullptr;
}
