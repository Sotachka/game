#pragma once
#include "Data.h"
class Player;
class Entity
{
public:
	std::string name;
	char sym;
	bool exist;
	Entity() { sym = ' '; exist = true; }
	virtual void ShowInfo();
	virtual void Command();
	virtual void Interact(Player& p, std::string cmd);
};