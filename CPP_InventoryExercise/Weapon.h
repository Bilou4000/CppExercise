#pragma once

#include "Item.h"
#include "ItemType.h"

class Weapon: public Item
{
public:
	Weapon(int id, int damage, int durability, std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect);

	void Attack();

	void SetDamage(int newDamage);
	void SetDurability(int newDurability);

	void ChangeDurability(int durability);

	void AddType(uint8_t type);
	void RemoveType(uint8_t type);

private:
	int mDamage = 3;
	int mDurability = 10;
};

