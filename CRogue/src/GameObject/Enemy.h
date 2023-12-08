#pragma once
#include "Entity.h"

class Enemy : public Entity {
public:
	Enemy(Vector2f pos, Animation anim, BoxCollider collider, float h, float d);
	void update()override;
	void onCollision(BoxCollider other, Vector2f delta) override;
};


