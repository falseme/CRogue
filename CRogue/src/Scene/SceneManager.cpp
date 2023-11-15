#include "SceneManager.h"

Scene * SceneManager::mainScene = NULL;

void SceneManager::loadScene() {
	mainScene = new TestScene(); // TEMP // TESTING
	mainScene->init();
}

void SceneManager::update() {
	mainScene->update();
}

void SceneManager::draw(RWindow* render) {
	mainScene->draw(render);
}