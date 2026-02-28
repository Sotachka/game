#pragma once
#include "Entity.h"
class Shop : public Entity
{
public:
	const Item* stock[5];
	Shop();
	Command* GetCommand(std::string cmd)override;
	void ShowInfo() override;
	void ShowCommand() override;	
};
class Tavern : public Entity
{
public:
	Tavern();	
	void ShowInfo() override;	
	void ShowCommand()override;		
	Command* GetCommand (std::string cmd)override;
};
class Mountain : public Entity
{
public:
	Mountain() { sym = '+'; }
};

