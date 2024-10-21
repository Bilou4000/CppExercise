#include "Item.h"

Item::Item(std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect)
{
	mName = name;
	mDescription = description;
	mCost = cost;
	mType = type;
	mEffect = effect;
}

void Item::SetType(std::uint8_t type)
{
	mType = type;
}

void Item::SetEffect(std::uint8_t effect)
{
	mEffect = effect;
}

std::uint8_t Item::GetType()
{
	return mType;
}

std::uint8_t Item::GetEffect()
{
	return mEffect;
}
