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
	if ((HasFlag(firstFood.GetType(), ConsumableType::Herb) && HasFlag(secondFood.GetType(), ConsumableType::Vegetable)) 
		|| (HasFlag(firstFood.GetType(), ConsumableType::Herb) && HasFlag(secondFood.GetType(), ConsumableType::Herb)) 
		|| (HasFlag(firstFood.GetType(), ConsumableType::Vegetable) && HasFlag(secondFood.GetType(), ConsumableType::Vegetable)))
	{
		Consumable* vegetableStew = new Consumable(mInventory->NewID(), ConsumableType::Food, "Vegetable Stew", "A nice soup", 5, ItemType::Consumable, ItemEffect::None);
		mInventory->AddToInventory(vegetableStew);
	}
	//if we have a meat and a mushroom or both -> Vegetable Stew
	if (HasFlag(firstFood.GetType(), ConsumableType::Meat) && HasFlag(secondFood.GetType(), ConsumableType::Mushroom))
	{
		Consumable* MushroomPremiumSteak = new Consumable(mInventory->NewID(), ConsumableType::Food, "Mushroom Premium Steak", "An incredibly delicious steak", 5, ItemType::Consumable, ItemEffect::None);
		mInventory->AddToInventory(MushroomPremiumSteak);
	}
	//if no specific recipe
	else
	{
		Consumable* weirdLookingFood = new Consumable(mInventory->NewID(), ConsumableType::Food, "A weird Looking Food", "Might be dangerous to eat it", 0, ItemType::Consumable, ItemEffect::None);
		mInventory->AddToInventory(weirdLookingFood);
	}

	mInventory->RemoveFromInventory(firstFood.GetID());
	mInventory->RemoveFromInventory(secondFood.GetID());
}
