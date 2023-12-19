#pragma once

#include "Entity.h"

class Player :public Entity {
public:
	const static int MAX_HEALTH = 8;
	Player(Vector2f pos, int h, int d, float speed);
	void update() override;
	void draw(RWindow* render) override;

	bool moving();
	bool attacking();
	bool healing();
private:
	bool showInventory;
};


