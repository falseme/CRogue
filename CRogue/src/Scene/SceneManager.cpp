#include "SceneManager.h"

#include "levels/LevelScene1.h"

Scene * SceneManager::mainScene = NULL;

void SceneManager::loadScene() {
	mainScene = new LevelScene1();
	mainScene->init();
}

void SceneManager::update() {
	mainScene->update();
}

void SceneManager::draw(RWindow* render) {
	mainScene->draw(render);
}