#include "Object.h"
#include "Player.h"
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
void Shop::Interact(Player& p, std::string cmd)
{
	if (cmd == "buy") {
		std::cout << "Какой предмет вы хотите приобрести?\nВведите номер предмета:" << std::endl;
		int index; std::cin >> index;
		if (index <= 5 && index > 0)
		{
			index -= 1;
			if (stock[index] != nullptr)
			{
				if (p.money < stock[index]->cost)
				{
					std::cout << "Вам не хватает денег на это!" << std::endl;
				}
				else
				{
					p.money -= stock[index]->cost;
					std::cout << "Вы купили: " << stock[index]->name << " ценой в " << stock[index]->cost << " денег" << std::endl;
					if (stock[index]->damage > 0)
					{
						p.weapon = stock[index];
					}
					else if (stock[index]->defense > 0)
					{
						p.armor = stock[index];
					}
					stock[index] = nullptr;
				}
			}
			else std::cout << "Этот предмет уже куплен!" << std::endl;
		}
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
Command* Tavern::Interact(std::string cmd)
{
	if (cmd == "command")
	{
	return new SleepCommand();
	}	
}