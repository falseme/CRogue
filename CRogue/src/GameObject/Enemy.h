#pragma once
#include "Entity.h"

class Enemy : public Entity {
public:
	Enemy(Vector2f pos, Texture* tex, float h, float d);
	void update()override;
};


