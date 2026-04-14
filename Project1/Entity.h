#pragma once
#include "Data.h"
class Command;
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
};