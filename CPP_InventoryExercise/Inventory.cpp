#include<algorithm>

#include "Inventory.h"
#include "ItemType.h"

//sort inventory (compare two item)
struct ItemSorting
{
	bool operator()(const Item* a, const Item* b)
	{
		return a->GetFirstType() < b->GetFirstType();
	}
};

//buy item
void Inventory::Buying(Item* item)
{
	int buyPrice = item->GetBuyPrice();
	std::string equipmentName = item->GetName();

	//check you have enough money
	if(mMoneyCount >= buyPrice)
	{
		// buy item -> lose money
		mMoneyCount -= buyPrice;
		// add it to inventory
		AddToInventory(item);
		printf("You bought %s for %i and now have %i coins \n", equipmentName.c_str(), buyPrice, mMoneyCount);
	}
	//if not -> can't buy
	else
	{
		printf("You don't have enougth money to buy %s. You only have %i coins \n", equipmentName.c_str(), mMoneyCount);
	}
}

//sell item
void Inventory::Selling(Item* item)
{
	int sellPrice = item->GetSellPrice();
	std::string equipmentName = item->GetName();

	//get money back
	mMoneyCount += sellPrice;
	printf("You sold %s for %i and now have %i coins \n", equipmentName.c_str(), sellPrice, mMoneyCount);
	//remove from inventory
	RemoveFromInventory(item->GetID());
}

//remove item from inventory from item id
void Inventory::RemoveFromInventory(int id)
{
	//for all items in inventory
	for(int i = 0; i < mInventory.size(); i++)
	{
		//check if item id has same id of an item in inventory
		if(mInventory[i]->GetID() == id)
		{
			/* UnloadTexture(mInventory[i]->GetTexture()); */
			//delete and erase item from inventory
			delete mInventory[i];
			mInventory.erase(mInventory.begin() + i);
			return;
		}
	}
}

//add item to inventory
void Inventory::AddToInventory(Item* item)
{
	//if inventory is not full
	if(mInventory.size() < mMaxInventorySize)
	{
		//for every item in inventory (backward iteration)
		for (size_t i = mInventory.size(); i--;)
		{
			//if an item has the same main type as your item
			if (item->GetFirstType() == mInventory[i]->GetFirstType())
			{
				//add item after it
				std::vector<Item*>::iterator it = mInventory.begin() + (i + 1);
				it = mInventory.insert(it, item);
				return;
			}
		}

		//if not -> add it at the end
		mInventory.push_back(item);
	}
	//if inventory is full
	else
	{
		printf("Your inventory is full.\n");
	}
}

//sort inventory -> call struct ItemSorting
void Inventory::SortInventory()
{
	std::sort(mInventory.begin(), mInventory.end(), ItemSorting {});
}

//return the inventory vector of items
std::vector<Item*>& Inventory::GetInventory()
{
	return mInventory;
}


//Get item in inventory from Id
Item* Inventory::GetInventoryItemFromID(int id) const
{
	for(int i = 0; i < mInventory.size(); i++)
	{
		if(mInventory[i]->GetID() == id)
		{
			Item* item = mInventory[i];
			return item;
		}
	}
}

//create new id everytime
int Inventory::NewID()
{
	mID++;
	return mID;
}
