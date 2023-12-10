#include "LevelScene.h"

#include <fstream>
#include <sstream>

#include "../GameObject/Player.h"
#include "../GameObject/Enemy.h"

LevelScene::LevelScene(int level) {
	this->level = level;
}

void LevelScene::init() {

	loadScene();

	addGameObject(new Player(Vector2f(40, 40), BoxCollider(Vector2f(14, 14)), 10, 5));
	addGameObject(new Enemy(Vector2f(80, 40), std::vector<Animation>{Animation(1.2f, Assets::skelyIdle, 6)}, BoxCollider(Vector2f(12, 16)), 10, 5));

	GameObject::setGameObjectCurrentList(&gameObjects);

}

void LevelScene::update() {

	for (GameObject* go : gameObjects) {
		go->update();
		checkCollision(go);
		checkTileCollision(go);
	}

}

void LevelScene::loadScene() {

	stringstream ss;
	ss << "data/assets/levels/" << level << ".leveldat";

	ifstream levelFile(ss.str());
	if (!levelFile.is_open())
		return;

	string l;
	int py = 0;
	while (getline(levelFile, l)) {

		for (int i = 0; i < l.size(); i++) {

			string complete = l.substr(i, 3);
			if (complete == "non") {
				i += 3;
				continue;
			}

			string sx = l.substr(i, 1);
			string sy = l.substr(++i, 1);
			string col = l.substr(++i, 1);
			i++; // so as to ignore the blanck space

			int tx = stoi(sx);
			int ty = stoi(sy);
			bool tcol = (bool)stoi(col);

			addTile(new Tile(Vector2f(i / 4, py), Vector2f(tx, ty), Assets::Tileset->copyToImage(), tcol));

		}

		py++;

	}

}

void LevelScene::checkCollision(GameObject* gameObject) {

	for (GameObject* go : gameObjects) {
		if (go == gameObject)
			continue;
		Vector2f d = gameObject->getCollider().collide(go->getCollider());
		if (d == Vector2f(0, 0))
			continue;
		gameObject->onCollision(go->getCollider(), d);
	}

}

void LevelScene::checkTileCollision(GameObject* gameObject) {

	for (Tile* t : tileset) {
		Vector2f d = gameObject->getCollider().collide(t->getCollider());
		if (d == Vector2f(0, 0))
			continue;
		gameObject->onCollision(t->getCollider(), d);
	}

}
