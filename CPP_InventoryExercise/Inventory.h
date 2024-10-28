#pragma once
#include "Item.h"

#include <vector>

class Inventory
{
public:
	void Buying(Item* equipment);
	void Selling(Item* equipment);

	void RemoveFromInventory(int id);
	void AddToInventory(Item* equipment);

	void SortInventory();

	std::vector<Item*>& GetInventory();
	Item* GetInventoryItemFromID(int id) const;
	int NewID();

private:
	const int mMaxInventorySize = 25;

	int mID = 0;
	int mMoneyCount = 500;

	std::vector<Item*> mInventory;
};

