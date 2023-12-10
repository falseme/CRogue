#pragma once

#include "Scene.h"

class LevelScene : public Scene {
private:
	int level;
public:
	LevelScene(int level);
	void init() override;
	void update() override;

	void loadScene() override;

	void checkCollision(GameObject* gameObject);
	void checkTileCollision(GameObject* gameObject);
};

