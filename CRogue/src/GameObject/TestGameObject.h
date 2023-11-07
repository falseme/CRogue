#pragma once

#include "GameObject.h"

class TestGameObject : public GameObject {
public:
	TestGameObject(Vector2f pos, Texture* tex);
	void update() override;
};

