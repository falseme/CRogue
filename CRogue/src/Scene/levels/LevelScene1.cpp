#include "LevelScene1.h"

#include "../../GameObject/Player.h"

LevelScene1::LevelScene1() {

}

void LevelScene1::init() {

	loadLevel(1);

	Animation playerAnimation(0.85f, Assets::playerIdle_anim, 4);
	addGameObject(new Player(Vector2f(40, 40), playerAnimation, BoxCollider(Vector2f(12, 12)), 10, 5));

}

void LevelScene1::update() {

	for (GameObject* go : gameObjects) {
		go->update();
		checkCollision(go);
		checkTileCollision(go);
	}

}

void LevelScene1::checkCollision(GameObject* gameObject) {

	for (GameObject* go : gameObjects) {
		if (go == gameObject)
			continue;
		if (gameObject->getCollider().collide(go->getCollider())) {
			gameObject->onCollision(go->getCollider());
		}
	}

}

void LevelScene1::checkTileCollision(GameObject* gameObject) {

	for (Tile* t : tileset) {
		if (gameObject->getCollider().collide(t->getCollider())) {
			gameObject->onCollision(t->getCollider());
		}
	}

}