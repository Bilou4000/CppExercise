#include "Item.h"

Item::Item(int id, std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect)
{
	mID = id;
	mName = name;
	mDescription = description;
	mCost = cost;
	mType = type;
	mEffect = effect;
	mFirstType = type;
}

void Item::SpreadFire()
{
	printf("Your %s is spreading fire ! \n", mName.c_str());
}

std::string Item::GetName() const
{
	return mName;
}

std::string Item::GetDescription() const
{
	return mDescription;
}

int Item::GetID() const
{
	return mID;
}

int Item::GetBuyPrice() const
{
	return mCost;
}

int Item::GetSellPrice() const
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

void Item::AddType(std::uint8_t type)
{
	mType = mType + (ItemType::Type) type;
}

void Item::RemoveType(std::uint8_t type)
{
	mType = mType - (ItemType::Type) type;
}

std::uint8_t Item::GetType() const
{
	return mType;
}

std::uint8_t Item::GetFirstType() const
{
	return mFirstType;
}

std::uint8_t Item::GetEffect() const
{
	return mEffect;
}
