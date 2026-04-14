#include "Enemy.h"
#include "Player.h"
#include "Command.h"
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


