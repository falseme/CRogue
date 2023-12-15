#include "SceneManager.h"

#include "LevelScene.h"

Scene* SceneManager::mainScene = NULL;
int SceneManager::currentLevel;
const int SceneManager::MAX_LEVEL;

void SceneManager::init() {
	currentLevel = 1;
	mainScene = new LevelScene(currentLevel);
	loadScene(mainScene);
}

void SceneManager::loadScene(Scene* scene) {
	scene->loadScene();
	scene->setCameraView(RWindow::get()->getView());
	scene->init();
}

void SceneManager::loadNextLevel() {

	currentLevel++;
	if (currentLevel > MAX_LEVEL)
		currentLevel--;

	LevelScene* ls = new LevelScene(currentLevel);
	loadScene(ls);

	delete mainScene;
	mainScene = ls;


}

void SceneManager::update() {
	mainScene->update();
}

void SceneManager::draw(RWindow* render) {
	mainScene->draw(render);
}

Scene* SceneManager::getCurrentScene() {
	return mainScene;
}