#pragma once
#include "Entity.h"

class Enemy : public Entity {
protected:
	int followDistance;
public:
	Enemy(Vector2f pos, vector<Animation> anim, BoxCollider collider, float h, float d, float speed, int attackDistance, int followDistance);
	void update()override;
	void onCollision(BoxCollider other, Vector2f delta) override;
};


