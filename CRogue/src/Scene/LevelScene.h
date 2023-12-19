#pragma once

#include "Scene.h"
#include <ui/SpriteImage.h>

class LevelScene : public Scene {
private:
	int level;
	int playerHealth;
	vector<SpriteImage*> GUIHealth;
public:
	LevelScene(int level, float accCamZoom, int playerHealth);
	void update(Vector2f mousePosition) override;
	void loadScene() override;

	string loadGameObject(char key, int x, int y);

	void checkCollision(GameObject* gameObject);
	void checkTileCollision(GameObject* gameObject);

	void updateGUIHealth(int health);
	int getPlayerHealth();
};

