#pragma once
#include "../GameObject/Player.h"

#include "Scene.h"
#include "../GameObject/TestGameObject.h"

/**
* A Scene used just for testing
*/
class TestScene : public Scene {
public:
	TestScene();
	void init() override;
	void update() override;
};

