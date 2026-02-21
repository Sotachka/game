#pragma once
#include "Player.h"
class Entity;
class Command
{
public:	
	~Command() {};
	virtual void Execute(Player* p, Entity *target) = 0;
};
class SleepCommand :public Command
{
public:
	SleepCommand() {};
	void Execute (Player*p, Entity* target)override
	{
		p->hp = 100;
		std::cout << "Ваше здоровье восстановлено." << std::endl;
	}
};
class BuyCommand : public Command 
{
public:
	void Execute (Player*p, Entity* target)
	{
	
	}
};
class AttackCommand : public Command
{
public:
	void Execute (Player*p, Entity* target)override
	{	

	}
};