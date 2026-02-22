#pragma once
#include "Player.h"
class Entity;
class Command
{
public:	
	~Command() {};
	virtual void Execute(Player* p, Entity *target) = 0;
};
class SleepCommand :public Command
{
public:
	SleepCommand() {};
	void Execute (Player*p, Entity* target)override
	{
		p->hp = 100;
		std::cout << "Ваше здоровье восстановлено." << std::endl;
	}
};
class BuyCommand : public Command 
{
public:
	void Execute (Player*p, Entity* target)
	{
	
	}
};
class AttackCommand : public Command
{
public:
	int Creature::CalculateDamage(int dmg, int crit, int armor)
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
	void Execute (Player*p, Entity* target)override
	{	
		target->hp -= CalculateDamage(p->weapon->damage, p->weapon->critical, p->armor);
		if (hp <= 0)
		{
			std::cout << "Враг умер." << " Обыскав " << target->name << " вы нашли " << target->money << " денег" << std::endl;
			p->money += target->money;
			std::cout << "Теперь у вас " << p->money << " денег" << std::endl;
			target->exist = false;
		}
		else
		{
			std::cout << "Теперь у врага " << hp << " здоровья" << std::endl;
			std::cout << "Враг атакует в ответ" << std::endl;
			p->hp -= p->CalculateDamage(target->weapon->damage, target->weapon->critical);
			std::cout << "Теперь у вас " << p->hp << " здоровья" << std::endl;
		}
	}
};