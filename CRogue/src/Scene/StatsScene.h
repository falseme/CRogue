#pragma once

#include "Scene.h"

class StatsScene : public Scene {
public:
	StatsScene(string title);
	void update(Vector2f mousePosition) override;
	void loadScene() override;
};

