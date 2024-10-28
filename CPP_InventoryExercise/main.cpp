#include <iostream>


#include "ConsumableType.h"
#include "ItemType.h"
#include "ItemEffect.h"

#include "Inventory.h"

#include "Weapon.h"
#include "Consumable.h"

Inventory* inventory = new Inventory();

// Example
int main()
{
    //create sword
    Weapon* sword = new Weapon(inventory->NewID(), 3, 5, "MagicSword", "The best sword", 10, ItemType::Weapon, ItemEffect::None );
    printf("Name : %s \n", sword->GetName().c_str());
    printf("Description : %s \n",sword->GetDescription().c_str());

    //attack without the tag Breakable
    printf("Type : %d\n", ( uint8_t ) sword->GetType());
    printf("ATTACK : ");
    sword->Attack();

    //add tag Breakable
    sword->AddType(ItemType::Breakable);
    printf("Add type Breakable to %s \n", sword->GetName().c_str());
    //attack again with tag
    printf("Type : %d\n", ( uint8_t ) sword->GetType());
    printf("ATTACK : ");
    sword->Attack();

    printf("-------------------------\n");
    //buy sword -> add to inventory
    inventory->Buying(sword);

    //create consumable and other weapon + add them to inventory
    Consumable* apple = new Consumable(inventory->NewID(), ConsumableType::Food, "Apple", "A big red apple", 1, ItemType::Consumable, ItemEffect::HeatResistance);
    inventory->Buying(apple);

    Weapon* axe = new Weapon(inventory->NewID(), 1, 10, "SturdyAxe", "The best axe", 3, ItemType::Weapon, ItemEffect::None);
    inventory->Buying(axe);

    Weapon* wand = new Weapon(inventory->NewID(), 10, 2, "MagicWand", "The best wand", 20, ItemType::Weapon, ItemEffect::Regen);
    inventory->Buying(wand);

    Consumable* speedPotion = new Consumable(inventory->NewID(), ConsumableType::Potion, "SpeedPotion", "A speed Potion", 5, ItemType::Consumable, ItemEffect::Speed);
    inventory->Buying(speedPotion);

    printf("-------------------------\n");

    //print all items
    printf("INVENTORY : \n");
    for (Item* item : inventory->GetInventory())
    {
        printf("%s \n", item->GetName().c_str());
        printf("%d\n", (uint8_t) item->GetFirstType());
        //printf("%d\n", item->GetID());
    }

    printf("-------------------------\n");
    //sell one item
    inventory->Selling(axe);

    //sort inventory
    inventory->SortInventory();

    printf("-------------------------\n");

    //print all items
    printf("INVENTORY : \n");
    for (Item* item : inventory->GetInventory())
    {
        printf("%s \n", item->GetName().c_str());
        printf("%d\n", (uint8_t) item->GetFirstType());
    }
}

