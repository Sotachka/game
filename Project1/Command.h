#pragma once
#include "Player.h"
class Entity;
class Command
{
public:	
	~Command() {};
	virtual void Execute() = 0;
};
class SleepCommand :public Command
{
	Player* player;
public:
	SleepCommand(Player* p){
		player = p;
	}
	void Execute ()override
	{
		player->hp = 100;
		std::cout << "Ваше здоровье восстановлено." << std::endl;
	}
};