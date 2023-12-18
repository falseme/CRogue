#include "HealthPotion.h"

HealthPotion::HealthPotion(Texture* tex, string name, int healing) : Item(tex, name) {
	this->healing = healing;
}

int HealthPotion::getHealing() {
	return healing;
}
