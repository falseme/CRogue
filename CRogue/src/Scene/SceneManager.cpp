#include "SceneManager.h"

#include "LevelScene.h"

Scene* SceneManager::mainScene = nullptr;
int SceneManager::currentLevel;
const int SceneManager::MAX_LEVEL;

void SceneManager::init() {
	currentLevel = 1;
	mainScene = new LevelScene(currentLevel, 0.1f);
	loadScene(mainScene);
}

void SceneManager::loadScene(Scene* scene) {
	scene->loadScene();
	scene->setCameraView(RWindow::get()->getDefaultView());
}

void SceneManager::loadNextLevel() {

	if (!mainScene->zoomIn(0.05f, 0.02f)) {
		mainScene->cameraFollow(mainScene->find("player")->getPos());
		return;
	}

	currentLevel++;
	if (currentLevel > MAX_LEVEL)
		currentLevel--;

	LevelScene* ls = new LevelScene(currentLevel, mainScene->getAccCamZoom());
	loadScene(ls);

	delete mainScene;
	mainScene = ls;

}

void SceneManager::update() {
	if (!mainScene->find("enemy"))
		loadNextLevel();
	else
		mainScene->update();
}

void SceneManager::draw(RWindow* render) {
	mainScene->draw(render);
}

Scene* SceneManager::getCurrentScene() {
	return mainScene;
}