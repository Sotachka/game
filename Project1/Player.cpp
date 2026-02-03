#include "Player.h"
#include "Map.h"
void Player::Control(Map & map)
{
	int drx = 0, dry = 0;
	std::string command;
	std::cout << "Комманды:\n1.left\n2.right\n3.up\n4.down\n5.info\n6.map" << std::endl;
	if (map.grid[row][col] != nullptr) map.grid[row][col]->Command();
	std::cin >> command;
	if (command == "up" || command == "down" || command == "right" || command == "left")
	{
		if (command == "up") { drx = -1; row += drx; col += dry; }
		else if (command == "down") { drx = 1; row += drx; col += dry; }
		else if (command == "left") { dry = -1; row += drx; col += dry; }
		else if (command == "right") { dry = 1; row += drx; col += dry; }
		if (map.grid[row][col] != nullptr && map.grid[row][col]->sym == '+')
		{
			std::cout << "Тут гора!" << std::endl;
			row -= drx; col -= dry;
		}
	}
	else
	{
		if (map.grid[row][col] != nullptr)
		{
			if (command == "info")
			{
				map.grid[row][col]->ShowInfo();
			}
			else if (command == "attack" || command == "sleep" || command == "buy")
			{
				map.grid[row][col]->Interact(*this, command);
				if (map.grid[row][col]->exist == false)
				{
					delete map.grid[row][col];
					map.grid[row][col] = nullptr;
				}
			}
		}
	}
}
void Player::Spawn(Entity * (&grid)[Map::HEIGHT][Map::WIDTH])
{
	row = rand() % Map::HEIGHT;
	col = rand() % Map::WIDTH;
	if (grid[row][col] == nullptr) {}
	else Spawn(grid);
}