#include "Enemy.h"
#include "Player.h"
Enemy::Enemy() {
	sym = 'E';
	name = data::adj[rand() % 15] + data::enemyNoun[rand() % 15];
	hp = 100; money = rand() % 30;
	armor = &data::GetArmors(rand() % 10);
	weapon = &data::GetWeapons(rand() % 10);
}
void Enemy::ShowInfo() 
{
	std::cout << "Тут враг " << name << "!" << "\nУ него " << hp << " очков здоровья, и " <<
		money << " денег\nВ руках он держит " << weapon->name << "\nНа нем " << armor->name << std::endl;
}
void Enemy::ShowCommand()
{
	std::cout << ".attack" << std::endl;
}
void Enemy::Interact(Player& p, std::string cmd)
{
	if (cmd == "attack")
	{
		hp -= CalculateDamage(p.weapon->damage, p.weapon->critical);
		if (hp <= 0)
		{
			std::cout << "Враг умер." << " Обыскав " << name << " вы нашли " << money << " денег" << std::endl;
			p.money += money;
			std::cout << "Теперь у вас " << p.money << " денег" << std::endl;
			exist = false;
		}
		else
		{
			std::cout << "Теперь у врага " << hp << " здоровья" << std::endl;
			std::cout << "Враг атакует в ответ" << std::endl;
			p.hp -= p.CalculateDamage(weapon->damage, weapon->critical);
			std::cout << "Теперь у вас " << p.hp << " здоровья" << std::endl;
		}
	}
}


