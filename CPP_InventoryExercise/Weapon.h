#pragma once

#include "Item.h"

class Weapon: public Item
{
public:
	Weapon(int id, int damage, int durability, std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect);

	void Attack();

	void SetDamage(int newDamage);
	void SetDurability(int newDurability);

	void ChangeDurability(int durability);

private:
	int mDamage = 3;
	int mDurability = 10;
};

