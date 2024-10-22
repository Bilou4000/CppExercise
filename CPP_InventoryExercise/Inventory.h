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

	std::vector<Item*> GetContent();
	Item* GetInventoryItemFromID(int id);
	int GetInventorySize();
	int GetID();

private:
	const int mInventorySize = 25;

	int mID = 0;
	int mMoneyCount = 500;

	std::vector<Item*> mInventory;


};

