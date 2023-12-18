#pragma once

#include "Item.h"

class HealthPotion : public Item {
public:
	HealthPotion(Texture* tex, string name, int healing);
	int getHealing();
private:
	int healing;
};

