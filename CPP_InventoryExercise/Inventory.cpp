#include "Inventory.h"

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
		}
	}
}

void Inventory::AddToInventory(Item* item)
{
	if(mInventory.size() < 25)
	{
		mInventory.push_back(item);
	}
	else
	{
		printf("Your inventory is full.\n");
	}
}

std::vector<Item*> Inventory::GetContent()
{
	return mInventory;
}

Item* Inventory::GetInventoryItemFromID(int id)
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

int Inventory::GetInventorySize()
{
	return mInventory.size();
}

int Inventory::GetID()
{
	mID++;
	return mID;
}
