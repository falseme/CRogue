#pragma once

#include "Scene.h"
#include <ui/SpriteImage.h>

class LevelScene : public Scene {
private:
	int level;
	int playerHealth, playerKeys, playerPotions, playerSmallPotions;
	vector<SpriteImage*> GUIHealth;
public:
	LevelScene(int level, float accCamZoom, int playerHealth, int keyCount, int potionCount, int smallPotionCount);
	void update(Vector2f mousePosition) override;
	void loadScene() override;

	string loadGameObject(char key, int x, int y);

	void checkCollision(GameObject* gameObject);
	void checkTileCollision(GameObject* gameObject);

	void updateGUIHealth(int health);
	void updatePlayerInventory(int playerKeys, int playerPotions, int playerSmallPotions);
	int getPlayerHealth();
	int getPlayerKeys();
	int getPlayerPotions();
	int getPlayerSmallPotions();
};

