#pragma once
#include "Entity.h"

class Enemy : public Entity {
protected:
	int followDistance;
public:
	Enemy(Vector2f pos, vector<Animation> anim, float h, float d, float speed, int attackDistance, int followDistance, float cooldownLimit);

	void update()override;
	void draw(RWindow* render) override;
};


