#include "Object.h"
#include "Player.h"
#include "Command.h"
Shop::Shop() {
	sym = 'S'; name = data::adj[rand() % 15] + data::noun[rand() % 15];
	for (int i = 0; i < 5; i++)
	{
		int index = rand() % 20;
		if (index < 10)
		{
			stock[i] = &data::GetWeapons(index);
		}
		else if (index >= 10)
		{
			stock[i] = &data::GetArmors(index - 10);
		}	
	}
}
void Shop::ShowInfo() 
{
	std::cout << "Добро пожаловать в магазин " << name << "!\n" << "Ассортимент Магазина: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if (stock[i] != nullptr)
		{
			std::cout << i + 1 << "." << stock[i]->name << " цена: " << stock[i]->cost << std::endl;
		}
		else std::cout << i + 1 << ".Предмет куплен." << std::endl;

	}
}
void Shop::ShowCommand() 
{
	std::cout << ".buy" << std::endl;
}
Command* Shop::GetCommand(std::string cmd)
{
	if (cmd == "buy") {
		return new BuyCommand();
	}
}
Tavern::Tavern()
{
	sym = 'T'; name = data::adj[rand() % 15] + data::noun[rand() % 15];
}
void Tavern::ShowInfo()
{
	std::cout << "Добро пожаловать в таверну " << name << "!" << std::endl;
}
void Tavern::ShowCommand()
{
	std::cout << ".sleep" << std::endl;
}
Command* Tavern::GetCommand(std::string cmd)
{
	if (cmd == "command")
	{
	return new SleepCommand();
	}	
}