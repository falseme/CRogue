#include "TestScene.h"
#include "../assets/Assets.h"
#include "../animation/Animation.h"

TestScene::TestScene() {

}

void TestScene::init() {

	Animation playerAnimation(0.85f, Assets::playerIdle_anim, 4);
	addGameObject(new Player(Vector2f(10, 10), playerAnimation, 10, 5));

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