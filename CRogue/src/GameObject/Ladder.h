#pragma once

#include "SceneObject.h"

class Ladder : public SceneObject {
public:
	Ladder(Vector2f pos);
	void onCollision(BoxCollider other, Vector2f delta) override;
};

