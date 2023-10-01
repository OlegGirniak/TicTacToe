#include <iostream>

#include "Player.h"


Player::Player(char playerCharacter)
	: playerCharacter(playerCharacter)
{
	std::cout << "\n\t" << char(199) << " Enter name : ";
	std::cin >> this->name;

	system("cls");

	this->point = 0;
}

Player::~Player()
{
	this->point = 0;
	this->playerCharacter = ' ';
}

const char& Player::GetPlayerCharacter() const
{
	return this->playerCharacter;
}

std::string Player::GetPlayerName() const
{
	return this->name;
}

void Player::DoStep(char field[9])
{
	std::cout << "\n\t" << char(199) << " Enter position {" << this->playerCharacter <<  "} : ";
	int userInputPosition;
	std::cin >> userInputPosition;

	bool ifCoorectUserInputPosition = false;

	while (!ifCoorectUserInputPosition)
	{
		if ((userInputPosition >= 1) && (userInputPosition <= 9) && (field[userInputPosition - 1] == ' '))
		{
			ifCoorectUserInputPosition = true;
		}
		else
		{
			std::cout << "\t|| Error, enter position again!\n";
			std::cout << "\t|| - Enter position: ";
			std::cin >> userInputPosition;
		}
	}

	field[userInputPosition - 1] = this->playerCharacter;

	system("cls");
}
