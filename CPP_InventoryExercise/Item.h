#pragma once
#include <string>

#include "Flammable.h"

class Item : public Flammable
{
public:
	Item(int id, std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect);

	void SpreadFire() override;

	std::string GetName() const;
	std::string GetDescription() const;
	int GetID() const;
	int GetBuyPrice() const;
	int GetSellPrice() const;

	void SetType(std::uint8_t type);
	void SetEffect(std::uint8_t effect);
	std::uint8_t GetType() const;
	std::uint8_t GetFirstType() const;
	std::uint8_t GetEffect() const;

protected:
	std::string mName = "ItemName";
	std::string mDescription = "An incredible item";
	std::uint8_t mType;
	std::uint8_t mFirstType;
	std::uint16_t mEffect;

	int mCost = 10;
	int mID = 0;
};

