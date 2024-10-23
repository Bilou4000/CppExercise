#include "Consumable.h"

Consumable::Consumable(int id, std::uint8_t consumableType,std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect)
	:Item(id, name, description, cost, type, effect)
{
	mConsumableType = consumableType;
}

void Consumable::SetType(std::uint8_t type)
{
	mConsumableType = type;
}

std::uint8_t Consumable::GetType() const
{
	return mConsumableType;
}

void Consumable::Consume()
{
	printf("You have consume %s", mName.c_str());
}
