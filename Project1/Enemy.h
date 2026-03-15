#pragma once
#include "Creature.h"
class Player;
class Enemy : public Creature
{
public:
	Enemy();
	void ShowInfo() override;	
	void ShowCommand()override;
	AttackCommand* (std::string cmd) override 
	{ return nullptr; };
};
