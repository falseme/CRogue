#pragma once

#include "Scene.h"

class PauseMenu : public Scene {
public:
	PauseMenu();
	void update(Vector2f mousePosition) override;
	void loadScene() override;
};

