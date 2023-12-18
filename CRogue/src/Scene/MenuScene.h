#pragma once

#include "Scene.h"

class MenuScene : public Scene {
public:
	MenuScene();
	void update(Vector2f mousePosition) override;
	void loadScene() override;
};

