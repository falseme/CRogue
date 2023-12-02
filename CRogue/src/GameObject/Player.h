#pragma once
#include "Entity.h"
class Player :public Entity {
public:
	Player(Vector2f pos, Animation anim, BoxCollider collider, float h, float d);
	void update() override;
	void onCollision(BoxCollider other) override;
};


