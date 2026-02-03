#pragma once
#include "Entity.h"
class Player;
class Map
{
public:
	static constexpr int HEIGHT = 30;
	static constexpr int WIDTH = 30;
	Entity* grid[HEIGHT][WIDTH];
	void FillGrid();
	void ShowGrid(Player& player);
	~Map()
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				delete grid[i][j];
			}
		}
	}
};
