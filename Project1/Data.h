#pragma once
#include <iostream>
#include <string>
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
	inline const Item& GetWeapons(int i) {
		return weapons[i];
	}
	inline const Item& GetArmors(int i) {
		return armors[i];
	}
}
