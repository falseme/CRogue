#include "SceneManager.h"

#include "LevelScene.h"

Scene* SceneManager::mainScene = nullptr;
int SceneManager::currentLevel = 1;
const int SceneManager::MAX_LEVEL = 2;
bool SceneManager::loadingNextLevel = false;

void SceneManager::init() {
	mainScene = new LevelScene(currentLevel, 0.15f);
	loadScene(mainScene);
}

void SceneManager::loadScene(Scene* scene) {
	scene->loadScene();
	scene->setCameraView(RWindow::get()->getDefaultView());
}

void SceneManager::loadNextLevel() {

	if (!mainScene->zoomIn(0.1f, 0.8f)) {
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
	loadingNextLevel = false;

}

void SceneManager::gotoNextLevel() {
	loadingNextLevel = true;
}

void SceneManager::update() {
	if (loadingNextLevel) {
		loadNextLevel();
		return;
	}
	mainScene->update();
}

void SceneManager::draw(RWindow* render) {
	mainScene->draw(render);
}

Scene* SceneManager::getCurrentScene() {
	return mainScene;
}