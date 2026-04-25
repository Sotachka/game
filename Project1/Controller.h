#pragma once	
#include <string>
#include "Command.h"
class Command;
class Map;
class Player;
class Controller
{
public:
	std::string command;
	static const int CMD_SIZE = 8;
	Command* AvailableCommands[CMD_SIZE];
	Controller() 
	{
	AvailableCommands[0] = new SleepCommand;
	AvailableCommands[1] = new BuyCommand;
	AvailableCommands[2] = new AttackCommand;
	AvailableCommands[3] = new InfoCommand;
	AvailableCommands[4] = new MoveUpCommand;
	AvailableCommands[5] = new MoveDownCommand;
	AvailableCommands[6] = new MoveRightCommand;
	AvailableCommands[7] = new MoveLeftCommand;
	}
	void DisplayCommands(Map& map, Player& p);
	void EnterCommands();
	void Actions(Map& map, Player& player);
};