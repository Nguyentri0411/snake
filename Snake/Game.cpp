#include "Game.h"

void Game::Logic()
{
	snake.Move();
	if (snake.x == fruit.x && snake.y == fruit.y)
	{
		score += 10;
		fruit.Generate(width, height);
		snake.Grow();
	}
	gameOver = snake.CheckCollision(width, height);
	if (gameOver) SaveHighScore();
}