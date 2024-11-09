#include "FoodProcessor.h"

FoodProcessor::FoodProcessor(Inventory* inventory)
{
	mInventory = inventory;
}

void FoodProcessor::Cook(Consumable& firstFood, Consumable& secondFood)
{
	printf("Trying to Cook ! \n");

	//check that both items can be cooked, if yes -> cook
	if(HasFlag(firstFood.GetType(), ConsumableType::Cookable) && HasFlag(secondFood.GetType(), ConsumableType::Cookable))
	{
		GetNewCookedItem(firstFood, secondFood);
	}
	//if not, don't cook
	else
	{
		printf("One or both of your items are not available for cooking. \nPlease try again with different items \n");
	}
}

void FoodProcessor::GetNewCookedItem(Consumable& firstFood, Consumable& secondFood)
{
	//if we have a herb or a vegetable or both -> Vegetable Stew
	if (HasFlag(firstFood.GetType(), ConsumableType::Herb) && HasFlag(secondFood.GetType(), ConsumableType::Vegetable))
	{
		Consumable* vegetable_Stew = new Consumable(mInventory->NewID(), ConsumableType::Food, "Vegetable Stew", "A nice soup", 5, ItemType::Consumable, ItemEffect::None);
		mInventory->AddToInventory(vegetable_Stew);

		mInventory->RemoveFromInventory(firstFood.GetID());
		mInventory->RemoveFromInventory(secondFood.GetID());
	}
}
