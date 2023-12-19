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
	static Scene* auxScene;
	static bool loadingNextLevel;
	static bool gamePaused;
public:
	static void init();
	static void loadScene(Scene* scene);
	static void loadNextLevel();
	static void gotoNextLevel();
	static void startGame();
	static void quitGame();
	static void pauseGame();
	static void showStats();
	static void showTutorial();
	static void update(Vector2f mousePosition);
	static void draw(RWindow* render);
	static Scene* getCurrentScene();
};

