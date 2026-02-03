#pragma once
#include "Data.h"
#include <iostream>
#include <string>
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