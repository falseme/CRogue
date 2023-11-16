#pragma once
#include "Entity.h"
class Player :public Entity {
public:
	Player(Vector2f pos, Animation anim, float h, float d);
	void update() override;
};


