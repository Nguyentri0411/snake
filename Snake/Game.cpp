#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>

void Game::Draw() 
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
		std::cout << "#";
	std::cout << std::endl;
	
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; i < width; j++) 
		{
			if (j == 0)
				std::cout << "#";
			if (i == snake.y && j == snake.x)
				std::cout << "O";
			else if (i == fruit.y && j == fruit.x)
				std::cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < snake.nTail; k++)
				{
					if (snake.tailX[k] == j && snake.tailY[k] == i)
					{
						std::cout << "o";
						print = true;
					}
				}
				if (!print)
					std::cout << " ";
			}
			if (j == width - 1)
				std::cout << "#";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < width + 2; i++)
		std::cout << "#";
	std::cout << std::endl;
	std::cout << "Score: " << score << "  High Score: " << highScore << std::endl;
}

void Game::Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a': snake.ChangeDirection(LEFT); break;
		case 'd': snake.ChangeDirection(RIGHT); break;
		case 'w': snake.ChangeDirection(UP); break;
		case 's': snake.ChangeDirection(DOWN); break;
		case 'x': gameOver = true; break;
		}
	}
}

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

void Game::LoadHighScore()
{
	std::ifstream file("highscore.txt");
	if (file.is_open())
	{
		file >> highScore;
		file.close();
	}
}

void Game::SaveHighScore()
{
	if (score > highScore)
	{
		highScore = score;
		std::ofstream file("highscore.txt");
		if (file.is_open())
		{
			file << highScore;
			file.close();
		}
	}
}

