#include "SceneManager.h"

#include "LevelScene.h"
#include "MenuScene.h"

Scene* SceneManager::mainScene = nullptr;
Scene* SceneManager::auxScene = nullptr;
int SceneManager::currentLevel = 1;
const int SceneManager::MAX_LEVEL = 3;
bool SceneManager::loadingNextLevel = false;

void SceneManager::init() {
	auxScene = new LevelScene(currentLevel, 0.15f, 0);
	loadScene(auxScene);
	mainScene = new MenuScene();
	loadScene(mainScene);
}

void SceneManager::loadScene(Scene* scene) {
	scene->setCameraView(RWindow::get()->getDefaultView());
	scene->loadScene();
}

void SceneManager::loadNextLevel() {

	if (!mainScene->zoomIn(0.1f, 0.8f)) {
		mainScene->cameraFollow(mainScene->find("player")->getPos());
		return;
	}

	currentLevel++;
	if (currentLevel > MAX_LEVEL)
		currentLevel--;

	LevelScene* ls = new LevelScene(currentLevel, mainScene->getAccCamZoom(), ((LevelScene*)mainScene)->getPlayerHealth());
	loadScene(ls);

	delete mainScene;
	mainScene = ls;
	loadingNextLevel = false;

}

void SceneManager::gotoNextLevel() {
	loadingNextLevel = true;
}

void SceneManager::startGame() {
	mainScene = auxScene;
	auxScene = nullptr;
}

void SceneManager::quitGame() {
	exit(0);
}

void SceneManager::update(Vector2f mousePosition) {
	if (loadingNextLevel) {
		loadNextLevel();
		return;
	}
	mainScene->update(mousePosition);
}

void SceneManager::draw(RWindow* render) {
	if (auxScene) {
		auxScene->draw(render);
	}
	mainScene->draw(render);
}

Scene* SceneManager::getCurrentScene() {
	return mainScene;
}


