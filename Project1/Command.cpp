#include "Command.h"
#include "Player.h"
#include "Entity.h"
#include "Creature.h"
#include "Data.h"
#include "Map"
#include "Object.h"
class Shop;
void SleepCommand::Execute(Player* p, Entity* (&grid)[30][30])
{
	p->hp = 100;
	std::cout << "Ваше здоровье восстановлено." << std::endl;
}
void BuyCommand::Execute(Player* p, Entity* (&grid)[30][30])
{
	Shop* target = dynamic_cast<Shop*>(grid[p->row][p->col]);
	std::cout << "Какой предмет вы хотите приобрести?\nВведите номер предмета:" << std::endl;
	int index; std::cin >> index;
	if (index <= 5 && index > 0)
	{
		index -= 1;
		if (target->stock[index] != nullptr)
		{
			if (p->money < target->stock[index]->cost)
			{
				std::cout << "Вам не хватает денег на это!" << std::endl;
			}
			else
			{
				p->money -= target->stock[index]->cost;
				std::cout << "Вы купили: " << target->stock[index]->name << " ценой в " << target->stock[index]->cost << " денег" << std::endl;
				if (target->stock[index]->damage > 0)
				{
					p->weapon = target->stock[index];
				}
				else if (target->stock[index]->defense > 0)
				{
					p->armor = target->stock[index];
				}
				target->stock[index] = nullptr;
			}
		}
		else std::cout << "Этот предмет уже куплен!" << std::endl;
	}
}
int AttackCommand::CalculateDamage(int dmg, int crit, const Item* armor)
{
	int takenDamage = 0;
	int critChance = rand() % 100;
	if (armor != nullptr)
	{
		if (dmg > armor->defense)
		{
			takenDamage = dmg - armor->defense;
		}
		else
		{
			takenDamage = 1;
		}
	}
	else
	{
		takenDamage += dmg;
	}
	if (critChance < crit)
	{
		takenDamage += crit;
		std::cout << "КРИТ!" << std::endl;
	}
	std::cout << "Было нанесено " << takenDamage << " урона" << std::endl;
	return takenDamage;
}
void AttackCommand::Execute(Player* p, Entity* (&grid)[30][30])
{
	Creature* target = dynamic_cast<Creature*>(grid[p->row][p->col]);
	target->hp -= CalculateDamage(p->weapon->damage, p->weapon->critical, target->armor);
	if (target->hp <= 0)
	{
		std::cout << "Враг умер." << " Обыскав " << grid[p->row][p->col]->name << " вы нашли " << target->money << " денег" << std::endl;
		p->money += target->money;
		std::cout << "Теперь у вас " << p->money << " денег" << std::endl;
		target->exist = false;
	}
	else
	{
		std::cout << "Теперь у врага " << target->hp << " здоровья" << std::endl;
		std::cout << "Враг атакует в ответ" << std::endl;
		p->hp -= CalculateDamage(target->weapon->damage, target->weapon->critical, p->armor);
		std::cout << "Теперь у вас " << p->hp << " здоровья" << std::endl;
	}
}
void InfoCommand::Execute(Player* p, Entity* (&grid)[30][30])
{
	grid[p->row][p->col]->ShowInfo();
}
void MoveUpCommand::Execute(Player* p, Entity* (&grid)[30][30])
{
	if (grid[p->row + dry][p->col] != nullptr && grid[p->row][p->col + dry]->sym == '+')
	{
		std::cout << "Тут гора!" << std::endl;
	}
	else
	{
		p->row += dry;
	}	
}
void MoveDownCommand::Execute(Player* p, Entity* (&grid)[30][30])
{
	if (grid[p->row + dry][p->col] != nullptr && grid[p->row + dry][p->col]->sym == '+')
	{
		std::cout << "Тут гора!" << std::endl;
	}
	else
	{
		p->row += dry;
	}
}
void MoveRightCommand::Execute(Player* p, Entity* (&grid)[30][30])
{
	if (grid[p->row][p->col + drx] != nullptr && grid[p->row][p->col + drx]->sym == '+')
	{
		std::cout << "Тут гора!" << std::endl;
	}
	else
	{
		p->col += drx;
	}
}
void MoveLeftCommand::Execute(Player * p, Entity*(&grid)[30][30])
{
	p->col += 1;
	Command::CanWeGo(p, grid, p->col, p->row);

	if (grid[p->row][p->col + drx] != nullptr && grid[p->row][p->col + drx]->sym == '+')
	{
		std::cout << "Тут гора!" << std::endl;
	}
	else
	{
		p->col += drx;
	}
}