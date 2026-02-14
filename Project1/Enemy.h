#pragma once
#include "Creature.h"
class Player;
class Enemy : public Creature
{
public:
	Enemy();
	void ShowInfo() override;	
	void ShowCommand()override;
	void Interact(Player& p, std::string cmd) override;
};
