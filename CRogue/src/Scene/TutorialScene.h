#pragma once

#include "Scene.h"

class TutorialScene : public Scene {
public:
	TutorialScene();
	void update(Vector2f mousePosition) override;
	void loadScene() override;
};

