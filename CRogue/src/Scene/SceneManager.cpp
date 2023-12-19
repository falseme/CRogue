#include "SceneManager.h"

#include "LevelScene.h"
#include "MenuScene.h"
#include "PauseMenu.h"
#include "StatsScene.h"
#include <gameObject/Player.h>

Scene* SceneManager::mainScene = nullptr;
Scene* SceneManager::auxScene = nullptr;
int SceneManager::currentLevel = 1;
const int SceneManager::MAX_LEVEL = 3;
bool SceneManager::loadingNextLevel = false;
bool SceneManager::gamePaused = true;

void SceneManager::init() {
	currentLevel = 1;
	auxScene = new LevelScene(currentLevel, 0.15f, 0, 0, 0, 0, 0);
	loadScene(auxScene);
	mainScene = new MenuScene();
	loadScene(mainScene);
	gamePaused = true;
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

	Player* pl = (Player*)mainScene->find("player");

	currentLevel++;
	if (currentLevel > MAX_LEVEL) {
		pl->saveStats(true, false);
		showStats();
		loadingNextLevel = false;
		return;
	}

	LevelScene* ls = new LevelScene(currentLevel, mainScene->getAccCamZoom(), pl->getHealth(), pl->getKeyCount(), pl->getPotionCount(), pl->getPotionSmallCount(), pl->getKills());
	loadScene(ls);

	mainScene = ls;
	loadingNextLevel = false;

}

void SceneManager::gotoNextLevel() {
	loadingNextLevel = true;
}

void SceneManager::startGame() {
	mainScene = auxScene;
	auxScene = nullptr;
	gamePaused = false;
}

void SceneManager::quitGame() {
	exit(0);
}

void SceneManager::pauseGame() {
	if (gamePaused) {
		mainScene = auxScene;
		auxScene = nullptr;
		gamePaused = false;
	}
	else {
		auxScene = mainScene;
		mainScene = new PauseMenu();
		loadScene(mainScene);
		gamePaused = true;
	}
}

void SceneManager::showStats() {

	if (gamePaused) {
		mainScene = new StatsScene("ESTADISTICAS");
		loadScene(mainScene);
	}
	else {
		auxScene = mainScene;
		mainScene = new StatsScene("JUEGO TERMINADO");
		loadScene(mainScene);
	}

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


