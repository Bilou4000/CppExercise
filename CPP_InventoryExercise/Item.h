#pragma once
#include <string>

#include "Flammable.h"

class Item : public Flammable
{
public:
	Item(int id, std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect);

	void SpreadFire() override;

	std::string GetName();
	std::string GetDescription();
	int GetID();
	int GetBuyPrice();
	int GetSellPrice();

	void SetType(std::uint8_t type);
	void SetEffect(std::uint8_t effect);
	std::uint8_t GetType();
	std::uint8_t GetEffect();

protected:
	std::string mName = "ItemName";
	std::string mDescription = "An incredible item";
	std::uint8_t mType;
	std::uint16_t mEffect;

	int mCost = 10;
	int mID = 0;
};

