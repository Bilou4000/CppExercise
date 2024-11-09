#include "Weapon.h"

Weapon::Weapon(int id, int damage, int durability, std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect)
	:Item(id, name, description, cost, type, effect)
{
	mDamage = damage;
	mDurability = durability;
}

void Weapon::Attack()
{
	printf("You did %i damage \n", mDamage);

	if (HasFlag(mType, ItemType::Breakable)) 
	{
		printf("You durability is now %i \n", mDurability);
		ChangeDurability(1);
	}
}

void Weapon::SetDamage(int newDamage)
{
	mDamage = newDamage;
}

void Weapon::SetDurability(int newDurability)
{
	mDurability = newDurability;
}

void Weapon::ChangeDurability(int durability)
{
	mDurability -= durability;
}
