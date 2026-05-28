#pragma once
#include <string>
class Entity;
class Player;
class Enemy;
class Item;
class Command
{
public:	
	~Command() {};
	virtual void Execute(Player*p, Entity*(&grid)[30][30]) = 0;
	void CanWeGo(Player* p, Entity* (&grid)[30][30], int& col, int& row, int drx, int dry);
	std::string commandName;
	int drx = 0;
	int dry = 0;
};
class SleepCommand :public Command
{
public:
	SleepCommand() 
	{
		commandName = "sleep";
	};
	void Execute(Player* p, Entity* (&grid)[30][30])override;
	
};
class BuyCommand : public Command 
{
public:
	BuyCommand()
	{
		commandName = "buy";
	}
	void Execute(Player* p, Entity* (&grid)[30][30])override;
};
class AttackCommand : public Command
{
public:
	AttackCommand()
	{
		commandName = "attack";
	}
	int CalculateDamage(int dmg, int crit, const Item* armor);
	void Execute(Player* p, Entity* (&grid)[30][30])override;
};
class InfoCommand : public Command 
{
public:
	InfoCommand()
	{
		commandName = "info";
	}
	void Execute(Player* p, Entity* (&grid)[30][30]) override;
};
class MoveUpCommand	: public Command 
{
public:
	int dry = -1;
	MoveUpCommand() 
	{
		commandName = "up";
	}
	void Execute(Player* p, Entity* (&grid)[30][30]) override;
};
class MoveDownCommand : public Command
{
public:
	int dry = 1;
	MoveDownCommand()
	{
		commandName = "down";
	}
	void Execute(Player* p, Entity* (&grid)[30][30])override;
};
class MoveRightCommand : public Command
{
public:
	int drx = 1;
	MoveRightCommand()
	{
		commandName = "right";
	}
	void Execute(Player* p, Entity* (&grid)[30][30])override;
};
class MoveLeftCommand : public Command
{
public:
	int drx = -1;
	MoveLeftCommand()
	{
		commandName = "left";
	}
	void Execute(Player* p, Entity* (&grid)[30][30])override;
};