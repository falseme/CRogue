#include "SceneManager.h"

#include "LevelScene.h"

Scene * SceneManager::mainScene = NULL;

void SceneManager::loadScene() {
	mainScene = new LevelScene(1);
	mainScene->loadScene();
	mainScene->init();
}

void SceneManager::update() {
	mainScene->update();
}

void SceneManager::draw(RWindow* render) {
	mainScene->draw(render);
}