#include "TestScene.h"

TestScene::TestScene() {

}

void TestScene::init() {
	addGameObject(new TestGameObject());
}

void TestScene::update() {

	for (list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); it++) {
		GameObject* go = *it;
		go->update();
	}

}