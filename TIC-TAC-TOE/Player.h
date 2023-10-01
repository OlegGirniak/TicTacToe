#pragma once
class Player
{
private:
	std::string name;

	int point;
	char playerCharacter;
	
public:
	Player(char playerCharacter);
	~Player();

	const char& GetPlayerCharacter() const;
	std::string GetPlayerName() const;

	void DoStep(char pole[9]);
};

