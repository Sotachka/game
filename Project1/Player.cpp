#include "Player.h"
#include "Map.h"
void Player::Spawn(Entity * (&grid)[Map::HEIGHT][Map::WIDTH])
{
	row = rand() % Map::HEIGHT;
	col = rand() % Map::WIDTH;
	if (grid[row][col] == nullptr) {}
	else Spawn(grid);
}