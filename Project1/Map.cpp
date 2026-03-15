#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Object.h"
void Map::FillGrid()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
			{
				grid[i][j] = new Mountain;
			}
			else
			{
				int chance = rand() % 100;
				if (chance < 2)
				{
					grid[i][j] = new Tavern();
				}
				else if (chance <= 3)
				{
					grid[i][j] = new Shop();
				}
				else if (chance < 5)
				{
					grid[i][j] = new Enemy();
				}
				else if (chance < 30)
				{
					grid[i][j] = new Mountain();
				}
				else { grid[i][j] = nullptr; }
			}
		}
	}
}
void Map::ShowGrid(Player& player)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == player.row && j == player.col)
			{
				std::cout << player.sym;
			}
			else if (grid[i][j] != nullptr)
			{
				std::cout << grid[i][j]->sym;
			}
			else std::cout << ' ';
		}
		std::cout << std::endl;
	}
}
