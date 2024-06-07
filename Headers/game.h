#ifndef GAME_H
#define GAME_H
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QObject>
#include<Qtimer>
#include"Player.h"
#include "score.h"
#include"health.h"
constexpr int Max_Game_Score = 20;
class Game
{
public:
    Game();
    ~Game();
    void display();
    Score* getGameScore() const noexcept;
    Health* getGamePlayerHealth() const noexcept;

public:
    volatile bool gameIsOver = false;
    QGraphicsScene* myScene = nullptr;
    QGraphicsView* myView =nullptr;

private:
    Player* player = nullptr;
    QTimer* timer =nullptr;
    Score* gameScore =nullptr;
    Health* playerGameHealth = nullptr;
};

#endif // GAME_H
