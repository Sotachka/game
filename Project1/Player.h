#pragma once
#include "Creature.h"
#include "Map.h"
class Player : public Creature
{
public:
	int row, col;
	Player() { sym = 'P'; hp = 100; money = 50; armor = nullptr; weapon = &data::GetWeapons(9);}
	void Spawn(Entity* (&grid)[Map::HEIGHT][Map::WIDTH]);
}; 