#include "TestScene.h"
#include "../assets/Assets.h"

TestScene::TestScene() {

}

void TestScene::init() {
	addGameObject(new Player(Vector2f(10, 10), Assets::player, 10, 5));
}

void TestScene::update() {

	/*for (list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); it++) {
		GameObject* go = *it;
		go->update();
	}*/

	for (GameObject* go : gameObjects) {
		go->update();
	}

}