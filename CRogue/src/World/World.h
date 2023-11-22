#pragma once

#include "Scene/Scene.h"
#include "Scene/TestScene.h"
#include "../UI/RWindow.h"

/**
* A static class that loads, updates & render scenes
*/
class World {
private:
	static Scene* mainScene;
public:
	static void loadScene();
	static void update();
	static void draw(RWindow* render);
};

