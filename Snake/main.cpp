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

int main()
{
	int choice;
	bool exit = false;
	int highScore = LoadHighScore();

	while (!exit)
	{
		system("cls");
		ShowMenu(highScore);
		std::cin >> choice;

		switch (choice)
		{
		case 1: {
			Game game(20, 20);
			game.Setup();
			while (!game.gameOver)
			{
				game.Draw();
				game.Input();
				game.Logic();
				Sleep(100);
			}
			highScore = LoadHighScore();
			break;
		}
		case 2:
			std::cout << "\nInstructions:\n";
			std::cout << "Use 'W' to move up\n";
			std::cout << "Use 'S' to move down\n";
			std::cout << "Use 'A' to move left\n";
			std::cout << "Use 'D' to move right\n";
			std::cout << "Press 'X' to exit the game\n";
			std::cout << "Press any key to return to the menu...\n";
			std::cin.get();
			std::cin.get();
			break;
		case 3:
			std::cout << "\nCurrent High Score: " << highScore << "\n";
			std::cout << "Press any key to return to the menu...\n";
			std::cin.get();
			std::cin.get();
			break;
		case 4:
			exit = true;
			break;
		default:
			std::cout << "Invalid option. Please try again.\n";
			Sleep(1000);
			break;
		}
	}
	std::cout << "Exiting the game!\n";
	return 0;
}