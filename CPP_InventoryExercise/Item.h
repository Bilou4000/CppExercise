#pragma once
#include <string>

class Item
{
public:
	Item(std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect);

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
};

