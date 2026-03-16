#pragma once
#include "Data.h"
#include "Command.h"
class Player;
class Entity
{
public:
	std::string name;
	char sym;
	bool exist;
	Entity() { sym = ' '; exist = true; }
	virtual void ShowInfo();
	virtual void ShowCommand();
	virtual Command* GetCommand(std::string cmd);
};