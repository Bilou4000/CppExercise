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
    Weapon* sword = new Weapon(inventory->GetID(), 3, 5, "MagicSword", "The best sword", 10, ItemType::Weapon, ItemEffect::None );
    printf("%s \n", sword->GetName().c_str());
    printf("%s \n",sword->GetDescription().c_str());

    printf("%d\n", ( uint8_t ) sword->GetType());
    sword->Attack();
    sword->AddType(ItemType::Breakable);
    printf("%d\n", ( uint8_t ) sword->GetType());
    sword->Attack();

    inventory->Buying(sword);
    //inventory->Selling(sword);

    Consumable* apple = new Consumable(inventory->GetID(), ConsumableType::Food, "Apple", "A big red apple", 1, ItemType::Consumable, ItemEffect::HeatResistance);
    inventory->Buying(apple);

    Weapon* axe = new Weapon(inventory->GetID(), 1, 10, "SturdyAxe", "The best axe", 3, ItemType::Weapon, ItemEffect::None);
    inventory->Buying(axe);


    for (Item* item : inventory->GetInventory())
    {
        printf("%s \n", item->GetName().c_str());
        printf("%d\n", item->GetFirstType());

    }

    inventory->SortInventory();

    for (Item* item : inventory->GetInventory())
    {
        printf("%s \n", item->GetName().c_str());
        printf("%d\n", (uint8_t) item->GetFirstType());

    }
}

