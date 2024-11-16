#ifndef SNAKE_H
#define SNAKE_H

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Snake
{
public:
	int x, y;
	int tailX[100], tailY[100];
	int nTail;
	eDirection dir;
	Snake(int startX, int startY);
};

#endif // SNAKE_H
