#pragma once

#include "Entity.h"

class Player :public Entity {
public:
	Player(Vector2f pos, BoxCollider collider, float h, float d, float speed);
	void update() override;
	void onCollision(BoxCollider other, Vector2f delta) override;
};


