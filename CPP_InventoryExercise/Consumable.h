#pragma once

#include "Item.h"
#include "ItemType.h"
#include "ConsumableType.h"

class Consumable : public Item
{
public:
	Consumable(int id, std::uint8_t consumableType, std::string name, std::string description, int cost, std::uint8_t type, std::uint8_t effect);

	void SetType(std::uint8_t type);
	std::uint8_t GetType() const;

	//add consumable type or remove one to item
	void AddConsumableType(std::uint8_t type);
	void RemoveConsumableType(std::uint8_t type);

	void Consume();

private:
	std::uint8_t mConsumableType;
};

