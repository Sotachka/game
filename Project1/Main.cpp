#include "Map.h"
#include "Player.h"
#include <iostream>
#include <ctime>
#include <string>
int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	Map map;
	Player player;
	map.FillGrid();
	player.Spawn(map.grid);
	map.ShowGrid(player);
	while (true)
	{
		if (player.hp <= 0)
		{
			std::cout << "\t  Вы погибли.\n\n\t Игра окончена." << std::endl;
			break;
		}
		else
		{
			player.Control(map);
			map.ShowGrid(player);
		}
	}
	return 0;
}