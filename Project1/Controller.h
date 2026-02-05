#pragma once	
#include "Map.h"
#include <string>
class Controller
{
public:
	int drx = 0; int dry = 0;
	std::string command;
	void DisplayCommands(Map &map, Player &p);
	void EnterCommands();
	void Actions(Map& map, Player& player);
};