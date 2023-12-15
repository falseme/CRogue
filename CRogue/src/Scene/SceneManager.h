#pragma once

#include "Scene.h"
#include <UI/RWindow.h>

/**
* A static class that loads, updates & render scenes
*/
class SceneManager {
private:
	static int currentLevel;
	static const int MAX_LEVEL = 2;
	static Scene* mainScene;
public:
	static void init();
	static void loadScene(Scene* scene);
	static void loadNextLevel();
	static void update();
	static void draw(RWindow* render);
	static Scene* getCurrentScene();
};

