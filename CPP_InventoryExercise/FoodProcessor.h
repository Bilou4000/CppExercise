#pragma once

#include "IBakable.h"
#include "ConsumableType.h"

#include "Inventory.h"
#include "ItemEffect.h"

class FoodProcessor : public IBakable
{
public:
	FoodProcessor(Inventory* inventory);

	void Cook(Consumable& firstFood, Consumable& secondFood) override;
	void GetNewCookedItem(Consumable &firstFood, Consumable &secondFood);

private:
	Inventory* mInventory = new Inventory();
};

