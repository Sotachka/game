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
	std::string commandName;
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