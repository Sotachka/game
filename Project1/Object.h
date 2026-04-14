#pragma once
#include "Entity.h"
class Shop : public Entity
{
public:
	const Item* stock[5];
	Shop();
	void ShowInfo() override;
	void ShowCommand() override;	
};
class Tavern : public Entity
{
public:
	Tavern();	
	void ShowInfo() override;	
	void ShowCommand()override;		
};
class Mountain : public Entity
{
public:
	Mountain() { sym = '+'; }
};

