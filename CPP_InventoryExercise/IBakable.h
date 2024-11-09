#pragma once

//Bakable interface that allows to cook

#include "Consumable.h"

class IBakable
{
	virtual void Cook(Consumable& firstFood, Consumable& secondFood) = 0;
};

