#include "Item.h"

Item::Item(int id, std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect)
{
	mName = name;
	mDescription = description;
	mCost = cost;
	mType = type;
	mEffect = effect;
}

void Item::SpreadFire()
{
	printf("Your %s is spreading fire ! \n", mName.c_str());
}

std::string Item::GetName()
{
	return mName;
}

std::string Item::GetDescription()
{
	return mDescription;
}

int Item::GetID()
{
	return mID;
}

int Item::GetBuyPrice()
{
	return mCost;
}

int Item::GetSellPrice()
{
	return mCost / 2;
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
