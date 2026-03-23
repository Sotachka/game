#pragma once
#include "Creature.h"
class Player;

class Enemy : public Creature
{
public:
	Enemy();
	void ShowInfo() override;	
	void ShowCommand()override;
	Command* GetCommand (std::string cmd) override;
};
