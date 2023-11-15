#pragma once

#include "Scene.h"
#include "TestScene.h"
#include "../UI/RWindow.h"

/**
* A static class that loads, updates & render scenes
*/
class SceneManager {
private:
	static Scene* mainScene;
public:
	static void loadScene();
	static void update();
	static void draw(RWindow* render);
};

