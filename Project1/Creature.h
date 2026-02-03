#pragma once
#include "Entity.h"
class Creature : public Entity
{
public:
	int hp, money;
	const Item* armor, * weapon;
	int CalculateDamage(int dmg, int crit);
};