#pragma once
#include "Entity.h"
#include "Data.h"
class Shop : public Entity
{
public:
	const Item* stock[5];
	Shop();
	void Interact(Player& p, std::string cmd)override;
	void ShowInfo() override;
	void Command() override;	
};
class Tavern : public Entity
{
public:
	Tavern();	
	void ShowInfo() override;	
	void Command()override;		
	void Interact(Player& p, std::string cmd)override;	
};
class Mountain : public Entity
{
public:
	Mountain() { sym = '+'; }
};

