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
	GameObject::setGameObjectCurrentList(&gameObjects);

	addGameObject(new Player(Vector2f(40, 40), BoxCollider(Vector2f(12, 12), Vector2f(0,2)), 10, 2, 1.5f));
	addGameObject(new Enemy(Vector2f(80, 40), vector<Animation>{Animation(1.2f, Assets::skelyIdle, 6), Animation(0.4f, Assets::skelyRun, 2), Animation(0.6f, Assets::skelyAttack, 5), Animation(0.5f, Assets::skelyStunned, 4)}, BoxCollider(Vector2f(12, 16)), 10, 1, 0.75f, 20, 100));

	addGameObject(new Enemy(Vector2f(40, 90), vector<Animation>{Animation(1.2f, Assets::skelyIdle, 6), Animation(0.4f, Assets::skelyRun, 2), Animation(0.6f, Assets::skelyAttack, 5), Animation(0.5f, Assets::skelyStunned, 4)}, BoxCollider(Vector2f(12, 16)), 10, 1, 0.75f, 20, 90));

}

void LevelScene::update() {

	// SORT USING Y POSITION
	gameObjects.sort([](GameObject* g1, GameObject* g2) {return g1->comp(g2); });

	for (GameObject* go : gameObjects) {
		go->update();
		checkCollision(go);
		checkTileCollision(go);
	}

}

void LevelScene::loadScene() {

	stringstream ss;
	ss << "data/lvds/ld" << level << ".lvd";

	ifstream levelFile(ss.str());
	if (!levelFile.is_open())
		return;

	string l;
	int py = 0;
	while (getline(levelFile, l)) {

		int px = 0;

		for (int i = 0; i < l.size(); i+=3) {

			string tileKey = l.substr(i, 2);
			if (tileKey == "00") {
				px += 16;
				continue;
			}

			bool collider = tileKey.front() == '#' ? true : false;
			int texIndex = rand() % Assets::tilemap[tileKey].size();

			addTile(new Tile(Vector2f(px,py), Assets::tilemap[tileKey][texIndex], collider));
			px += 16;

		}

		py+=16;

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
