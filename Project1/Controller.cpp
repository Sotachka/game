#include "Controller.h"
#include "Player.h"
#include "Map.h"
#include "Command.h"	
void Controller::DisplayCommands(Map& map, Player& player)
{
	int ind = 1;
	if (map.grid[player.row - 1][player.col] == nullptr || map.grid[player.row - 1][player.col]->sym != '+')
	{
		std::cout << ind++ << ".up" << std::endl;
	}
	if (map.grid[player.row + 1][player.col] == nullptr || map.grid[player.row + 1][player.col]->sym != '+')
	{
		std::cout << ind++ << ".down" << std::endl;
	}
	if (map.grid[player.row][player.col - 1] == nullptr || map.grid[player.row][player.col - 1]->sym != '+')
	{
		std::cout << ind++ << ".left" << std::endl;
	}
	if (map.grid[player.row][player.col + 1] == nullptr || map.grid[player.row][player.col + 1]->sym != '+')
	{
		std::cout << ind++ << ".right" << std::endl;
	}
	if (map.grid[player.row][player.col] != nullptr)
	{
		std::cout << ind++ << ".info\n" << ind++; map.grid[player.row][player.col]->ShowCommand();
	}
}
void Controller::EnterCommands()
{
	drx = dry = 0;
	std::cin >> command;
}
void Controller::Actions(Map& map, Player& player)
{
	if (command == "up" || command == "down" || command == "left" || command == "right")
	{
		if (command == "up") { drx = -1;}
		else if (command == "down") { drx = 1; }
		else if (command == "left") { dry = -1; }
		else if (command == "right") { dry = 1; }
		if (map.grid[player.row + drx][player.col + dry] != nullptr && map.grid[player.row + drx][player.col + dry]->sym == '+')
		{
			std::cout << "Тут гора!" << std::endl;
		}
		else
		{
			player.row += drx; player.col += dry;
		}
	}
	else
	{
		if (map.grid[player.row][player.col] != nullptr)
		{
			if (command == "info")
			{
				map.grid[player.row][player.col]->ShowInfo();
			}
			else 
			{
				for (int i = 0; i < 3; i++)
				{
					if (AvailableCommands[i]->commandName == command)
					{
						AvailableCommands[i]->Execute(&player, map.grid);
						break;
					}
				}
			}
		}
	}
}
