#pragma once
#include "../GameObject/Player.h"

#include "Scene.h"

/**
* A Scene used just for testing
*/
class TestScene : public Scene {
public:
	TestScene();
	void init() override;
	void update() override;
};

