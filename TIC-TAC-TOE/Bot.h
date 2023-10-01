#pragma once
#include <iostream>

class Player;

class Bot
{
private:
	std::string name;
	char character;

	int points;
public:
	Bot(char character);
	~Bot();

	const char& GetCharacter() const;
	std::string GetName() const;

	void DoStep(char* pole, const Player& player);
};

