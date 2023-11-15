#pragma once
#include "Entity.h"
class Player :public Entity {
public:
	Player(Vector2f pos, Texture* tex, float h, float d);
	void update() override;
};


