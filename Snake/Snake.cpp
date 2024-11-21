#include "Snake.h"

Snake::Snake(int startX, int startY)
{
    x = startX;
    y = startY;
    nTail = 0;
    dir = STOP;
}

void Snake::ChangeDirection(eDirection newDir)
{
    dir = newDir;
}

void Snake::Move()
{
    for (int i = nTail - 1; i > 0; i--)
    {
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }
    if (nTail > 0)
    {
        tailX[0] = x;
        tailY[0] = y;
    }

    switch (dir)
    {
    case LEFT: x--; break;
    case RIGHT: x++; break;
    case UP: y--; break;
    case DOWN: y++; break;
    default: break;
    }
}

bool Snake::CheckCollision(int width, int height)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return true;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            return true;

    return false;
}

void Snake::Grow()
{
    nTail++;
}
