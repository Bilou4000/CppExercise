#include <iostream>


#include "ConsumableType.h"
#include "ItemType.h"
#include "ItemEffect.h"

#include "Inventory.h"

#include "Weapon.h"
#include "Consumable.h"

Inventory* inventory = new Inventory();

int main()
{
    Weapon* sword = new Weapon(inventory->NewID(), 3, 5, "MagicSword", "The best sword", 10, ItemType::Weapon, ItemEffect::None );
    printf("%s \n", sword->GetName().c_str());
    printf("%s \n",sword->GetDescription().c_str());

    printf("%d\n", ( uint8_t ) sword->GetType());
    sword->Attack();
    sword->AddType(ItemType::Breakable);
    printf("%d\n", ( uint8_t ) sword->GetType());
    sword->Attack();

    inventory->Buying(sword);

    Consumable* apple = new Consumable(inventory->NewID(), ConsumableType::Food, "Apple", "A big red apple", 1, ItemType::Consumable, ItemEffect::HeatResistance);
    inventory->Buying(apple);

    Weapon* axe = new Weapon(inventory->NewID(), 1, 10, "SturdyAxe", "The best axe", 3, ItemType::Weapon, ItemEffect::None);
    inventory->Buying(axe);

    Weapon* wand = new Weapon(inventory->NewID(), 10, 2, "MagicWand", "The best wand", 20, ItemType::Weapon, ItemEffect::Regen);
    inventory->Buying(wand);

    Consumable* speedPotion = new Consumable(inventory->NewID(), ConsumableType::Potion, "SpeedPotion", "A speed Potion", 5, ItemType::Consumable, ItemEffect::Speed);
    inventory->Buying(speedPotion);


    for (Item* item : inventory->GetInventory())
    {
        printf("%s \n", item->GetName().c_str());
        printf("%d\n", (uint8_t) item->GetFirstType());
        //printf("%d\n", item->GetID());
    }

    inventory->Selling(axe);

    inventory->SortInventory();
    printf("-------------------------\n");

    for (Item* item : inventory->GetInventory())
    {
        printf("%s \n", item->GetName().c_str());
        printf("%d\n", (uint8_t) item->GetFirstType());
    }
}

