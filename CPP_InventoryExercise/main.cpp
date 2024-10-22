#include <iostream>

#include "Weapon.h"
#include "ItemType.h"
#include "ItemEffect.h"
#include "Inventory.h"

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
    inventory->Selling(sword);
}

