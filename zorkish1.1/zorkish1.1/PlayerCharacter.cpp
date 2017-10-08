#include "PlayerCharacter.h"
#include "zorkish1.h"



PlayerCharacter::PlayerCharacter()
{
}


PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::printName() const
{
	std::cout << this->characterName;
}

void PlayerCharacter::initialize(const std::string name)
{
	this->characterName = name;
}