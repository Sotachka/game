#pragma once
class Entity;
class Player;
class Enemy;
class Item;
class Command
{
public:	
	~Command() {};
	virtual void Execute(Player*p, Entity*(&grid)[30][30]) = 0;
};
class SleepCommand :public Command
{
public:
	SleepCommand() {};
	void Execute(Player* p, Entity* (&grid)[30][30])override;
	
};
class BuyCommand : public Command 
{
public:
	void Execute(Player* p, Entity* (&grid)[30][30])override;
	
};
class AttackCommand : public Command
{
public:
	int CalculateDamage(int dmg, int crit, const Item* armor);
	void Execute(Player* p, Entity* (&grid)[30][30])override;
	
};