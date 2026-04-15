#pragma once	
#include <string>
#include "Command.h"
class Command;
class Map;
class Player;
class Controller
{
public:
	int drx = 0; int dry = 0;
	std::string command;
	static const int CMD_SIZE = 4;
	Command* AvailableCommands[CMD_SIZE];
	Controller() 
	{
	AvailableCommands[0] = new SleepCommand;
	AvailableCommands[1] = new BuyCommand;
	AvailableCommands[2] = new AttackCommand;
	AvailableCommands[3] = new InfoCommand;
	}
	void DisplayCommands(Map& map, Player& p);
	void EnterCommands();
	void Actions(Map& map, Player& player);
};