#pragma once

#include "Entity.h"

class Player :public Entity {
public:
	Player(Vector2f pos, float h, float d, float speed);
	void update() override;
	void draw(RWindow* render) override;

	bool moving();
	bool attacking();
private:
	bool showInventory;
};


