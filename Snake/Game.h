#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "Fruit.h"



class Game
{
public:
    const int width, height;
    bool gameOver;
    int score;
    int highScore;
    Snake snake;
    Fruit fruit;

    Game(int w, int h);
    void Setup();
    void Draw();
    void Input();
    void Logic();
    void LoadHighScore();
    void SaveHighScore();
};

#endif // GAME_H
