#include "Consumable.h"

Consumable::Consumable(std::uint8_t consumableType,std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect):Item(name, description, cost, type, effect)
{
	mConsumableType = consumableType;
}

void Consumable::SetType(std::uint8_t type)
{
	mConsumableType = type;
}

std::uint8_t Consumable::GetType()
{
	return mConsumableType;
}

void Consumable::Consume()
{
	delete(this);
}
