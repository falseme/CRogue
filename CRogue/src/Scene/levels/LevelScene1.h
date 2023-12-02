#pragma once

#include "../Scene.h"

class LevelScene1 : public Scene {
public:
	LevelScene1();
	void init() override;
	void update() override;
	void checkCollision(GameObject* gameObject);
	void checkTileCollision(GameObject* gameObject);
};

