#pragma once

#include "SceneObject.h"
#include <assets/Assets.h>

class Door : public SceneObject {
public:
	Door(Vector2f pos);
	void update() override;
	void onCollision(BoxCollider other, Vector2f delta) override;
private:
	bool open;
};

