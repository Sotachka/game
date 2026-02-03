#include"Creature.h"
int Creature::CalculateDamage(int dmg, int crit)
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