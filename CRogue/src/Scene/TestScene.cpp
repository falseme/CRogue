#include "TestScene.h"
#include "../assets/Assets.h"
#include "../animation/Animation.h"

TestScene::TestScene() {

}

void TestScene::init() {

	loadLevel();

	Animation playerAnimation(0.85f, Assets::playerIdle_anim, 4);
	addGameObject(new Player(Vector2f(10, 10), playerAnimation, 10, 5));

}

void TestScene::update() {

	for (GameObject* go : gameObjects) {
		go->update();
	}

}
void TestScene::loadLevel() {
	for (int i = 0; i < 5; i++) {
		addTile(new Tile(Vector2f(i, 0), Vector2f(2, 0), Assets::Tileset->copyToImage()));
	}


}