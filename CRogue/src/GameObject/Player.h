#pragma once

#include "Entity.h"

typedef struct {
	int kills, totalKills, victories, losses;
} UserStats;

class Player :public Entity {
public:
	const static int MAX_HEALTH = 8;
	Player(Vector2f pos, int h, int d, float speed, int keys, int potions, int smallPotions, int kills);
	void update() override;
	void draw(RWindow* render) override;

	bool moving();
	bool attacking();
	bool healing();

	void saveStats(bool victory, bool loss);
private:
	bool showInventory;
};


