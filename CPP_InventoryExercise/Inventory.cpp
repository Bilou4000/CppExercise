#include<algorithm>

#include "Inventory.h"
#include "ItemType.h"

struct ItemSorting
{
	bool operator()(const Item* a, const Item* b)
	{
		return a->GetFirstType() < b->GetFirstType();
	}
};

void Inventory::Buying(Item* item)
{
	int buyPrice = item->GetBuyPrice();
	std::string equipmentName = item->GetName();

	if(mMoneyCount >= buyPrice)
	{
		mMoneyCount -= buyPrice;
		AddToInventory(item);
		printf("You bought %s for %i and now have %i coins \n", equipmentName.c_str(), buyPrice, mMoneyCount);
	}
	else
	{
		printf("You don't have enougth money to buy %s. You only have %i coins \n", equipmentName.c_str(), mMoneyCount);
	}
}

void Inventory::Selling(Item* item)
{
	int sellPrice = item->GetSellPrice();
	std::string equipmentName = item->GetName();

	mMoneyCount += sellPrice;
	printf("You sold %s for %i and now have %i coins \n", equipmentName.c_str(), sellPrice, mMoneyCount);
	RemoveFromInventory(item->GetID());
}

void Inventory::RemoveFromInventory(int id)
{
	for(int i = 0; i < mInventory.size(); i++)
	{
		if(mInventory[i]->GetID() == id)
		{
			//UnloadTexture(mInventory[i]->GetTexture());
			delete mInventory[i];
			mInventory.erase(mInventory.begin() + i);
			return;
		}
	}
}

void Inventory::AddToInventory(Item* item)
{
	if(mInventory.size() < mMaxInventorySize)
	{
		for (size_t i = mInventory.size(); i--;)
		{
			if (item->GetFirstType() == mInventory[i]->GetFirstType())
			{
				std::vector<Item*>::iterator it = mInventory.begin() + (i + 1);
				it = mInventory.insert(it, item);
				return;
			}
		}

		mInventory.push_back(item);
	}
	else
	{
		printf("Your inventory is full.\n");
	}
}

void Inventory::SortInventory()
{
	std::sort(mInventory.begin(), mInventory.end(), ItemSorting {});
}

std::vector<Item*>& Inventory::GetInventory()
{
	return mInventory;
}

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

int Inventory::NewID()
{
	mID++;
	return mID;
}
