#pragma once

#include "Item.h"

class Consumable : public Item
{
public:
	Consumable(int id, std::uint8_t consumableType, std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect);

	void SetType(std::uint8_t type);
	std::uint8_t GetType();

	void Consume();


private:
	std::uint8_t mConsumableType;
};

