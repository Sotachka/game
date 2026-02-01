#include <iostream>
#include <ctime>
#include <string>
class Player;
class Item {
public:
	std::string name;
	int damage, defense, cost, critical;
	Item()
	{
		name = "Пусто"; damage = 0; defense = 0; cost = 0; critical = 0;
	}
	Item(std::string nm, int dmg, int def, int cst, int crit)
	{
		name = nm;
		damage = dmg;
		defense = def;
		cost = cst;
		critical = crit;
	}
};
namespace data
{
	static inline const std::string adj[15] = {
"Многопоточный ","Дипломированный ","Просроченный ","Острый ","Бюджетный ","Полусладкий ","Скрипучий ","Угловатый ","Склизкий ","Хрустящий ","Лицензированный ","Дефицитный ","Загадочный ","Гнилой ","Грозный "
	};
	static inline const std::string noun[15] = {
	"Погреб","Притон","Чердак","Пост","Храм","Шкаф","Пень","Куст","Сапог","Кирпич","Гвоздь","Кабан","Сундук","Коридор","Гараж"
	};
	static inline const std::string enemyNoun[15] = {
"Окурок", "Паразит", "Сорняк", "Клещ", "Грызун","Слизень", "Паук", "Кабан", "Бомж", "Скелет","Простофиля", "Бес", "Труп", "Огузок", "Мутант"
	};
	static inline const Item weapons[10]
	{
		Item("Тяжелый тесак", 40, 0, 25, 5),
		Item("Боевой молот", 30, 0, 18, 2),
		Item("Короткий меч", 30, 0, 15, 10),
		Item("Охотничий нож", 15, 0, 5, 20),
		Item("Боевой топор", 50, 0, 35, 5),
		Item("Деревянная палица", 25, 0, 12, 3),
		Item("Стальной кинжал", 20, 0, 15, 25),
		Item("Шипастый цеп", 45, 0, 30, 5),
		Item("Железное копье", 35, 0, 20, 8),
		Item("Старая кирка", 28, 0, 10, 15)
	};
	static inline const Item armors[10]
	{
		Item("Кожаный нагрудник", 0, 15, 10, 0),
		Item("Стальной шлем", 0,     20, 15, 0),
		Item("Кольчужные рукавицы",0,12, 10, 0),
		Item("Стеганый ватник", 0,   8, 5, 0),
		Item("Тяжелые сапоги", 0,   10, 12, 0),
		Item("Чешуйчатый пояс", 0,   5, 8, 0),
		Item("Рыцарские поножи", 0, 18, 25, 0),
	 Item("Пластинчатые наручи", 0, 14, 15, 0),
		Item("Меховой плащ", 0,      6, 7, 0),
	Item("Старая ношеная одежда", 0, 1, 1, 0)
	};
	const Item& GetWeapons(int i) {
		return weapons[i];
	}
	const Item& GetArmors(int i) {
		return armors[i];
	}
}
class Entity
{
public:
	std::string name;
	char sym;
	bool exist;
	Entity() { sym = ' '; exist = true; }
	virtual void ShowInfo() {}
	virtual void Command() {}
	virtual void Interact(Player& p, std::string cmd) {}
};
class Creature : public Entity
{
public:
	int hp, money;
	const Item* armor, * weapon;
	int CalculateDamage(int dmg, int crit)
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
};
class Shop : public Entity
{
public:
	const Item* stock[5];
	Shop() {
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
	void Interact(Player& p, std::string cmd)override;
	void ShowInfo() override
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
	void Command() override
	{
		std::cout << "7.buy" << std::endl;
	}
};
class Tavern : public Entity
{
public:
	Tavern()
	{
		sym = 'T'; name = data::adj[rand() % 15] + data::noun[rand() % 15];
	}
	void ShowInfo() override
	{
		std::cout << "Добро пожаловать в таверну " << name << "!" << std::endl;
	}
	void Command()override
	{
		std::cout << "7.sleep" << std::endl;
	}
	void Interact(Player& p, std::string cmd)override;
};
class Enemy : public Creature
{
public:
	Enemy() {
		sym = 'E';
		name = data::adj[rand() % 15] + data::enemyNoun[rand() % 15];
		hp = 100; money = rand() % 30;
		armor = &data::GetArmors(rand() % 10);
		weapon = &data::GetWeapons(rand() % 10);
	}
	void ShowInfo() override
	{
		std::cout << "Тут враг " << name << "!" << "\nУ него " << hp << " очков здоровья, и " <<
			money << " денег\nВ руках он держит " << weapon->name << "\nНа нем " << armor->name << std::endl;
	}
	void Command()override
	{
		std::cout << "7.attack" << std::endl;
	}
	void Interact(Player& p, std::string cmd) override;
};
class Mountain : public Entity
{
public:
	Mountain() { sym = '+'; }
};
class Map
{
public:
	static constexpr int HEIGHT = 30;
	static constexpr int WIDTH = 30;
	Entity* grid[HEIGHT][WIDTH];
	void FillGrid()
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{

				if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
				{
					grid[i][j] = new Mountain;
				}
				else
				{
					int chance = rand() % 100;
					if (chance < 2)
					{
						grid[i][j] = new Tavern();
					}
					else if (chance <= 3)
					{
						grid[i][j] = new Shop();
					}
					else if (chance < 5)
					{
						grid[i][j] = new Enemy();
					}
					else if (chance < 30)
					{
						grid[i][j] = new Mountain();
					}
					else { grid[i][j] = nullptr; }
				}
			}
		}
	}
	void ShowGrid(Player& player);
	~Map()
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				delete grid[i][j];
			}
		}
	}
};
class Player : public Creature
{
public:
	int row, col;
	Player() { sym = 'P'; hp = 100; money = 50; armor = nullptr; weapon = &data::GetWeapons(9); }
	void Spawn(Entity* (&grid)[Map::HEIGHT][Map::WIDTH])
	{
		row = rand() % Map::HEIGHT;
		col = rand() % Map::WIDTH;
		if (grid[row][col] == nullptr) {}
		else Spawn(grid);
	}
	void Control(Map& map)
	{
		int drx = 0, dry = 0;
		std::string command;
		std::cout << "Комманды:\n1.left\n2.right\n3.up\n4.down\n5.info\n6.map" << std::endl; if (map.grid[row][col] != nullptr) map.grid[row][col]->Command();
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
};
void Tavern::Interact(Player& p, std::string cmd)
{
	if (cmd == "sleep") {
		p.hp = 100;
		std::cout << "Ваше здоровье на высоте!" << std::endl;
	}
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
void Map::ShowGrid(Player& player)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == player.row && j == player.col)
			{
				std::cout << player.sym;
			}
			else if (grid[i][j] != nullptr)
			{
				std::cout << grid[i][j]->sym;
			}
			else std::cout << ' ';
		}
		std::cout << std::endl;
	}
}
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