#pragma once

#include "Scene.h"
#include <ui/RWindow.h>

/**
* A static class that loads, updates & render scenes
*/
class SceneManager {
private:
	static int currentLevel;
	static const int MAX_LEVEL;
	static Scene* mainScene;
	static bool loadingNextLevel;
public:
	static void init();
	static void loadScene(Scene* scene);
	static void loadNextLevel();
	static void gotoNextLevel();
	static void update();
	static void draw(RWindow* render);
	static Scene* getCurrentScene();
};

