#include "Bot.h"
#include "Player.h"

Bot::Bot(char character) 
{
	this->name = "BOT Arthur";
	this->character = character;
	points = 0;
}

Bot::~Bot()
{
	points = 0;
	character = ' ';
}

const char& Bot::GetCharacter() const
{
	return this->character;
}

std::string Bot::GetName() const
{
	return this->name;
}

void Bot::DoStep(char* pole, const Player& player)
{
	int botChoice;

	//check center
	if (pole[4] == ' ')
	{
		pole[4] = this->character;
		system("cls");
		return;

	}

	// check rows;
	for (size_t i = 0; i <= 6; i+=3)
	{
		if ((pole[i] == this->character && pole[i + 1] == this->character && pole[i + 2] == ' ') || (pole[i] == player.GetPlayerCharacter() && pole[i + 1] == player.GetPlayerCharacter() && pole[i + 2] == ' '))
		{
			pole[i + 2] = this->character;
			system("cls");
			return;
		}

		if ((pole[i] == this->character && pole[i + 2] == this->character && pole[i + 1] == ' ') || (pole[i] == player.GetPlayerCharacter() && pole[i + 2] == player.GetPlayerCharacter() && pole[i + 1] == ' '))
		{
			pole[i + 1] = this->character;
			system("cls");
			return;
		}

		if ((pole[i + 1] == this->character && pole[i + 2] == this->character && pole[i] == ' ') || (pole[i + 1] == player.GetPlayerCharacter() && pole[i + 2] == player.GetPlayerCharacter() && pole[i] == ' '))
		{
			pole[i] = this->character;
			system("cls");
			return;
		}
	}

	//check cols
	for (size_t i = 0; i < 3; i++)
	{
		if ((pole[i] == pole[i + 3] && pole[i + 3] == this->character && pole[i + 6] == ' ') || (pole[i] == pole[i + 3] && pole[i + 3] == player.GetPlayerCharacter() && pole[i + 6] == ' '))
		{
			pole[i + 6] = this->character;
			system("cls");
			return;
		}
		if ((pole[i + 3] == pole[i + 6] && pole[i + 6] == this->character && pole[i] == ' ') || (pole[i + 3] == pole[i + 6] && pole[i + 6] == player.GetPlayerCharacter() && pole[i] == ' '))
		{
			pole[i] = this->character;
			system("cls");
			return;
		}
		if ((pole[i] == pole[i + 6] && pole[i + 6] == this->character && pole[i + 3] == ' ') || (pole[i] == pole[i + 6] && pole[i + 6] == player.GetPlayerCharacter() && pole[i + 3] == ' '))
		{
			pole[i + 3] = this->character;
			system("cls");
			return;
		}
	}

	//check diagonals
	if ((pole[0] == this->character && pole[4] == this->character && pole[8] == ' ') || (pole[0] == player.GetPlayerCharacter() && pole[4] == player.GetPlayerCharacter() && pole[8] == ' '))
	{
		pole[8] = this->character;
		system("cls");
		return;
	}
	if ((pole[2] == this->character && pole[4] == this->character && pole[6] == ' ') || (pole[2] == player.GetPlayerCharacter() && pole[4] == player.GetPlayerCharacter() && pole[6] == ' '))
	{
		pole[6] = this->character;
		system("cls");
		return;
	}

	if ((pole[4] == this->character && pole[8] == this->character && pole[0] == ' ') || (pole[4] == player.GetPlayerCharacter() && pole[8] == player.GetPlayerCharacter() && pole[0] == ' '))
	{
		pole[0] = this->character;
		system("cls");
		return;
	}
	if ((pole[4] == this->character && pole[6] == this->character && pole[2] == ' ') || (pole[4] == player.GetPlayerCharacter() && pole[6] == player.GetPlayerCharacter() && pole[2] == ' '))
	{
		pole[2] = this->character;
		system("cls");
		return;
	}
	
	if ((pole[0] == this->character && pole[8] == this->character && pole[4] == ' ') || (pole[0] == player.GetPlayerCharacter() && pole[8] == player.GetPlayerCharacter() && pole[4] == ' '))
	{
		pole[4] = this->character;
		system("cls");
		return;
	}
	if ((pole[2] == this->character && pole[6] == this->character && pole[4] == ' ') || (pole[2] == player.GetPlayerCharacter() && pole[6] == player.GetPlayerCharacter() && pole[4] == ' '))
	{
		pole[4] = this->character;
		return;
	}

	//check left bottom corner
	if (pole[6] == ' ')
	{
		pole[6] = this->character;
		system("cls");
		return;
	}

	//random choice
	while (true)
	{
		botChoice = rand() % 9 + 1;
		if (pole[botChoice] == ' ')
		{
			pole[botChoice] = this->character;
			system("cls");
			return;
		}
	}
}
