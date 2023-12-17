#pragma once

#include "Scene.h"

class LevelScene : public Scene {
private:
	int level;
public:
	LevelScene(int level, float accCamZoom);
	void update() override;
	void loadScene() override;

	void loadGameObject(char key, int x, int y);

	void checkCollision(GameObject* gameObject);
	void checkTileCollision(GameObject* gameObject);
};

