#include "LevelScene1.h"

#include "../../GameObject/Player.h"

LevelScene1::LevelScene1() {

}

void LevelScene1::init() {

	loadLevel(1);

	addGameObject(new Player(Vector2f(40, 40), BoxCollider(Vector2f(16, 16)), 10, 5));

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
		Vector2f d = gameObject->getCollider().collide(go->getCollider());
		if (d == Vector2f(0, 0))
			continue;
		gameObject->onCollision(go->getCollider(), d);
	}

}

void LevelScene1::checkTileCollision(GameObject* gameObject) {

	for (Tile* t : tileset) {
		Vector2f d = gameObject->getCollider().collide(t->getCollider());
		if (d == Vector2f(0, 0))
			continue;
		gameObject->onCollision(t->getCollider(), d);
	}

}