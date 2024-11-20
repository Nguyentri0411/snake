#include "Game.h"
#include <iostream>
#include <fstream>
#include <windows.h>

void ShowMenu(int highScore)
{
	std::cout << "====================\n";
	std::cout << "     Snake Game     \n";
	std::cout << "====================\n";
	std::cout << "1. Start Game\n";
	std::cout << "2. Instructions\n";
	std::cout << "3. High Scores (Current: " << highScore << ")\n";
	std::cout << "4. Exit\n";
	std::cout << "Select an option: ";
}

int LoadHighScore()
{
	int highScore = 0;
	std::ifstream file("highscore.txt");
	if (file.is_open())
	{
		file >> highScore;
		file.close();
	}
	return highScore;
}

int main() {
	return 0;
}