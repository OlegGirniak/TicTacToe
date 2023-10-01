#include <iostream>
#include <ctime>
#include "Player.h"
#include "Bot.h"

int PlayerMenu();
int PLayerBotMenu();
void ShowPole(char pole[9]);

bool CheckWinner(char field[9], Player& player1, Player& player2);
bool CheckWinner(char field[9], Player& player, Bot& bot);

bool CheckDraw(char pole[9]);


void StartGame(char* pole, Player& player1, Player& player2);
void StartGame(char* pole, Player& player, Bot& bot);
void StartGame(char* pole, Bot& bot, Player& player);


int main()
{
	char field[] = { ' ', ' ', ' ',
					' ', ' ', ' ',
					' ', ' ', ' ' };


	switch (PlayerMenu())
	{
	case 1:
	{
		std::cout << "\n\t" << char(199) << " Player | 1 | { X }  ";
		Player player1('X');

		std::cout << "\n\t" << char(199) << " Player | 2 | { O }  ";
		Player player2('O');
		StartGame(field, player1, player2);
		break;
	}

	case 2:
	{
		int playerChoice = PLayerBotMenu();

		if (playerChoice == 1)
		{
			Bot bot('O');

			Player player('X');

			StartGame(field, player, bot);
		}
		else if (playerChoice == 2)
		{
			Bot bot('X');

			Player player('O');

			StartGame(field, bot, player);
		}
		else
		{
			system("cls");
		}
		
		break;
	}
	case 3:
	{
		system("cls");
		system("pause");
		break;
	}
	default:
		break;
	}
}


int PlayerMenu()
{
	bool ifPlayerChoiceIsCorrect = false;

	while (!ifPlayerChoiceIsCorrect)
	{
		std::cout << "\n";
		std::cout << "\t" << char(199) << "1-| Start Game with PLAYER\n";
		std::cout << "\t" << char(199) << "2-| Start Game with BOT\n";
		std::cout << "\t" << char(199) << "3-| Exit\n\n";
		std::cout << "\t" << char(205) << " Enter choise: ";
		int playerChoice;
		std::cin >> playerChoice;

		if (playerChoice >=1 && playerChoice <= 3)
		{
			system("cls");
			return playerChoice;
		}
		system("cls");
	}
}

int PLayerBotMenu()
{
	bool ifPlayerChoiceIsCorrect = false;

	while (!ifPlayerChoiceIsCorrect)
	{
		std::cout << "\n";
		std::cout << "\t" << char(199) << "1-| Player { X } , BOT { O }\n";
		std::cout << "\t" << char(199) << "2-| BOT { X } , Player { O }\n";
		std::cout << "\t" << char(199) << "3-| Exit\n\n";
		std::cout << "\t" << char(205) << " Enter choise: ";
		int playerChoice;
		std::cin >> playerChoice;

		if (playerChoice >= 1 && playerChoice <= 3)
		{
			system("cls");
			return playerChoice;
		}
		system("cls");
	}
}

void ShowPole(char pole[9])
{

	std::cout << "\t" << char(201) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(187) << std::endl;
	std::cout << "\t" << char(186) << " " << "1" << " " << char(186) << " " << "2" << " " << char(186) << " " << "3" << " " << char(186) << std::endl;

	std::cout << "\t" << char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << std::endl;
	std::cout << "\t" << char(186) << " " << "4" << " " << char(186) << " " << "5" << " " << char(186) << " " << "6" << " " << char(186) << std::endl;

	std::cout << "\t" << char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << std::endl;
	std::cout << "\t" << char(186) << " " << "7" << " " << char(186) << " " << "8" << " " << char(186) << " " << "9" << " " << char(186) << std::endl;

	std::cout << "\t" << char(200) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(188) << std::endl;


	std::cout << std::endl;


	std::cout << "\t" << char(201) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(187) << std::endl;
	std::cout << "\t" << char(186) << " " << pole[0] << " " << char(186) << " " << pole[1] << " " << char(186) << " " << pole[2] << " " << char(186) << std::endl;

	std::cout << "\t" << char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << std::endl;
	std::cout << "\t" << char(186) << " " << pole[3] << " " << char(186) << " " << pole[4] << " " << char(186) << " " << pole[5] << " " << char(186) << std::endl;

	std::cout << "\t" << char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << std::endl;
	std::cout << "\t" << char(186) << " " << pole[6] << " " << char(186) << " " << pole[7] << " " << char(186) << " " << pole[8] << " " << char(186) << std::endl;

	std::cout << "\t" << char(200) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(188) << std::endl;
}


bool CheckWinner(char field[9], Player& player1, Player& player2)
{
	bool ifSomeBodyIsWinner = false;

	//check rows
	for (size_t i = 0; i < 7; i+=3)
	{
		if ((field[i] == field[i + 1]) && (field[i + 1] == field[i + 2]) && (field[i] == field[i + 2]) && (field[i] != ' '))
		{
			if (field[i] == player1.GetPlayerCharacter())
			{
				std::cout << "\t" << char(201) << "------------------------------" << std::endl;
				std::cout << "\t" << char(182) << " Player: " << player1.GetPlayerName() << " is WINNER" << std::endl;
				std::cout << "\t" << char(200) << "------------------------------" << std::endl;
			}
			else if (field[i] == player2.GetPlayerCharacter())
			{
				std::cout << "\t" << char(201) << "------------------------------" << std::endl;
				std::cout << "\t" << char(182) << " Player: " << player2.GetPlayerName() << " is WINNER" << std::endl;
				std::cout << "\t" << char(200) << "------------------------------" << std::endl;
			}
			return true;
		}
	}

	//check cols
	for (size_t i = 0; i < 3; i++)
	{
		if ((field[i] == field[i + 3]) && (field[i + 3] == field[i + 6]) && (field[i] != ' '))
		{
			if (field[i] == player1.GetPlayerCharacter())
			{
				std::cout << "\t" << char(201) << "------------------------------" << std::endl;
				std::cout << "\t" << char(182) << " Player: " << player1.GetPlayerName() << " is WINNER" << std::endl;
				std::cout << "\t" << char(200) << "------------------------------" << std::endl;
			}
			else if (field[i] == player2.GetPlayerCharacter())
			{
				std::cout << "\t" << char(201) << "------------------------------" << std::endl;
				std::cout << "\t" << char(182) << " Player: " << player2.GetPlayerName() << " is WINNER" << std::endl;
				std::cout << "\t" << char(200) << "------------------------------" << std::endl;
			}
			return true;
		}
	}
	
	//check main diagonals
	if (((field[0] == field[4]) && (field[4] == field[8]) && 
		(field[0] != ' ')) || ((field[2] == field[4]) && 
		(field[4] == field[6]) && (field[2] != ' ')))
	{
		if (field[4] == player1.GetPlayerCharacter())
		{
			std::cout << "\n";

			std::cout << "\t" << char(201) << "------------------------------" << std::endl;
			std::cout << "\t" << char(182) <<" Player: " << player1.GetPlayerName() << " is WINNER" << std::endl;
			std::cout << "\t" << char(200) << "------------------------------" << std::endl;
		}
		else 
		{

			std::cout << "\t" << char(201) << "------------------------------" << std::endl;
			std::cout << "\t" << char(182) << " Player: " << player2.GetPlayerName() << " is WINNER" << std::endl;
			std::cout << "\t" << char(200) << "------------------------------" << std::endl;
		}
		return true;
	}

	return ifSomeBodyIsWinner;
}

bool CheckWinner(char field[9], Player& player, Bot& bot)
{
	bool ifSomeBodyIsWinner = false;

	//check rows
	for (size_t i = 0; i < 7; i += 3)
	{
		if ((field[i] == field[i + 1]) && (field[i + 1] == field[i + 2]) && (field[i] == field[i + 2]) && (field[i] != ' '))
		{
			if (field[i] == player.GetPlayerCharacter())
			{
				std::cout << "\t" << char(201) << "------------------------------" << std::endl;
				std::cout << "\t" << char(182) << " Player: " << player.GetPlayerName() << " is WINNER" << std::endl;
				std::cout << "\t" << char(200) << "------------------------------" << std::endl;
			}
			else if (field[i] == bot.GetCharacter())
			{
				std::cout << "\t" << char(201) << "------------------------------" << std::endl;
				std::cout << "\t" << char(182) << " Player: " << bot.GetName() << " is WINNER" << std::endl;
				std::cout << "\t" << char(200) << "------------------------------" << std::endl;
			}
			return true;
		}
	}

	//check cols
	for (size_t i = 0; i < 3; i++)
	{
		if ((field[i] == field[i + 3]) && (field[i + 3] == field[i + 6]) && (field[i] != ' '))
		{
			if (field[i] == player.GetPlayerCharacter())
			{
				std::cout << "\t" << char(201) << "------------------------------" << std::endl;
				std::cout << "\t" << char(182) << " Player: " << player.GetPlayerName() << " is WINNER" << std::endl;
				std::cout << "\t" << char(200) << "------------------------------" << std::endl;
			}
			else if (field[i] == bot.GetCharacter())
			{
				std::cout << "\t" << char(201) << "------------------------------" << std::endl;
				std::cout << "\t" << char(182) << " Player: " << bot.GetName() << " is WINNER" << std::endl;
				std::cout << "\t" << char(200) << "------------------------------" << std::endl;
			}
			return true;
		}
	}

	//check main diagonals
	if (((field[0] == field[4]) && (field[4] == field[8]) &&
		(field[0] != ' ')) || ((field[2] == field[4]) &&
			(field[4] == field[6]) && (field[2] != ' ')))
	{
		if (field[4] == player.GetPlayerCharacter())
		{
			std::cout << "\n";

			std::cout << "\t" << char(201) << "------------------------------" << std::endl;
			std::cout << "\t" << char(182) << " Player: " << player.GetPlayerName() << " is WINNER" << std::endl;
			std::cout << "\t" << char(200) << "------------------------------" << std::endl;
		}
		else
		{

			std::cout << "\t" << char(201) << "------------------------------" << std::endl;
			std::cout << "\t" << char(182) << " Player: " << bot.GetName() << " is WINNER" << std::endl;
			std::cout << "\t" << char(200) << "------------------------------" << std::endl;
		}
		return true;
	}

	return ifSomeBodyIsWinner;
}


bool CheckDraw(char pole[9])
{
	for (size_t i = 0; i < 9; i++)
	{
		if (pole[i] == ' ')
		{
			return false;
		}
	}

	std::cout << "\n       || IT IS DRAW ||\n";
	return 1;
}
		

void StartGame(char* pole, Player& player1, Player& player2)
{
	system("cls");
	std::cout << "\n\t"  << player1.GetPlayerName() << "| - against - |" << player2.GetPlayerName() << std::endl;
	std::cout << std::endl;
	system("pause");
	system("cls");

	bool ifEndGame = false;

	while (!ifEndGame)
	{
		ShowPole(pole);

		player1.DoStep(pole);

		if (CheckWinner(pole, player1, player2))
		{
			ShowPole(pole);
			return;
		}

		if (CheckDraw(pole))
		{
			ShowPole(pole);
			return;
		}

		ShowPole(pole);

		player2.DoStep(pole);

		if (CheckWinner(pole, player1, player2))
		{
			ShowPole(pole);
			return;
		}

		if (CheckDraw(pole))
		{
			ShowPole(pole);
			return;
		}
	}
}

void StartGame(char* pole, Player& player, Bot& bot)
{
	system("cls");
	std::cout << "\n\t" << player.GetPlayerName() << "| - against - |" << bot.GetName() << std::endl;
	std::cout << std::endl;
	system("pause");
	system("cls");

	bool ifEndGame = false;

	while (!ifEndGame)
	{
		ShowPole(pole);

		player.DoStep(pole);

		if (CheckWinner(pole, player, bot))
		{
			ShowPole(pole);
			return;
		}

		if (CheckDraw(pole))
		{
			ShowPole(pole);
			return;
		}

		ShowPole(pole);

		bot.DoStep(pole, player);

		if (CheckWinner(pole, player, bot))
		{
			ShowPole(pole);
			return;
		}

		if (CheckDraw(pole))
		{
			ShowPole(pole);
			return;
		}
	}
}

void StartGame(char* pole, Bot& bot, Player& player)
{
	system("cls");
	std::cout << "\n\t" << player.GetPlayerName() << "| - against - |" << bot.GetName() << std::endl;
	std::cout << std::endl;
	system("pause");
	system("cls");

	bool ifEndGame = false;

	while (!ifEndGame)
	{
		ShowPole(pole);

		bot.DoStep(pole, player);

		if (CheckWinner(pole, player, bot))
		{
			ShowPole(pole);
			return;
		}

		if (CheckDraw(pole))
		{
			ShowPole(pole);
			return;
		}

		ShowPole(pole);

		player.DoStep(pole);

		if (CheckWinner(pole, player, bot))
		{
			ShowPole(pole);
			return;
		}

		if (CheckDraw(pole))
		{
			ShowPole(pole);
			return;
		}
	}
}