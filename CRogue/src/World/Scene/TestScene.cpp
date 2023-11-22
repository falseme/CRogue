#include "TestScene.h"
#include "../../assets/Assets.h"

TestScene::TestScene() {

}

void TestScene::init() {
	addGameObject(new TestGameObject(Vector2f(10, 10), Assets::player));
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