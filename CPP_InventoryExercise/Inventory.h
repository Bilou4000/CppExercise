#pragma once
#include "Item.h"

#include <vector>
//#include <map>

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
	int GetID();

private:
	const int mInventorySize = 25;

	int mID = 0;
	int mMoneyCount = 500;

	std::vector<Item*> mInventory;
	//std::map<uint8_t, Item*> mTypeInventory;
};

