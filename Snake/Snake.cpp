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