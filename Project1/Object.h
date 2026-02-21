#pragma once
#include "Entity.h"
class Shop : public Entity
{
public:
	const Item* stock[5];
	Shop();
	void Interact(Player& p, std::string cmd)override;
	void ShowInfo() override;
	void ShowCommand() override;	
};
class Tavern : public Entity
{
public:
	Tavern();	
	void ShowInfo() override;	
	void ShowCommand()override;		
	Command* Interact(std::string cmd)override;
};
class Mountain : public Entity
{
public:
	Mountain() { sym = '+'; }
};

