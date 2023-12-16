#include "LevelScene.h"

#include <fstream>
#include <sstream>
#include <time.h>

#include <gameObject/Player.h>
#include <gameObject/Enemy.h>

LevelScene::LevelScene(int level, float accCamZoom) : Scene(accCamZoom) {
	this->level = level;
}

void LevelScene::update() {

	if (!zoomOut(0.32f, 0.02f)) {
		cameraFollow(find("player")->getPos());
		return;
	}

	// SORT USING 'Y' POSITION
	gameObjects.sort([](GameObject* g1, GameObject* g2) { return g1->comp(g2); });

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

	srand(time(NULL));
	string l;
	int py = 0;
	while (getline(levelFile, l)) {

		if (l.empty() || l.front() == '%') // % -> comment
			continue;

		int px = 0;
		for (int i = 0; i < l.size(); i += 3) {

			string tileKey = l.substr(i, 2);
			if (tileKey == "00") {
				px += 16;
				continue;
			}

			if (tileKey.front() == '&') {
				//add GO
				tileKey = "O0";
			}

			bool collider = tileKey.front() == '#' ? true : false;
			int texIndex = rand() % Assets::tilemap[tileKey].size();

			addTile(new Tile(Vector2f(px, py), Assets::tilemap[tileKey][texIndex], collider));
			px += 16;

		}

		py += 16;

	}

	levelFile.close();

	//TEST GAMEOBJECTS

	addGameObject(new Player(Vector2f(40, 40), BoxCollider(Vector2f(12, 12), Vector2f(0, 2)), 10, 2, 1.5f));

	addGameObject(new Enemy(Vector2f(80, 40), vector<Animation>{Animation(1.2f, Assets::skelyIdle, 6), Animation(0.4f, Assets::skelyRun, 2), Animation(0.6f, Assets::skelyAttack, 5), Animation(0.5f, Assets::skelyStunned, 4)}, BoxCollider(Vector2f(12, 12), Vector2f(0, 2)), 10, 1, 0.75f, 20, 100));
	//addGameObject(new Enemy(Vector2f(40, 90), vector<Animation>{Animation(1.2f, Assets::skelyIdle, 6), Animation(0.4f, Assets::skelyRun, 2), Animation(0.6f, Assets::skelyAttack, 5), Animation(0.5f, Assets::skelyStunned, 4)}, BoxCollider(Vector2f(12, 12), Vector2f(0, 2)), 10, 1, 0.75f, 20, 90));
	//addGameObject(new Enemy(Vector2f(120, 90), vector<Animation>{Animation(1.2f, Assets::skelyIdle, 6), Animation(0.4f, Assets::skelyRun, 2), Animation(0.6f, Assets::skelyAttack, 5), Animation(0.5f, Assets::skelyStunned, 4)}, BoxCollider(Vector2f(12, 12), Vector2f(0, 2)), 10, 1, 0.75f, 20, 90));

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

	/*/
	#if 0
		Vector2f v_max = { 0,0 }; double d_max = 0;
		Tile* t_max = nullptr;
		for (Tile* t : tileset) {
			Vector2f v_aux = gameObject->getCollider().collide(t->getCollider());
			double d_aux = std::max(std::fabs(v_aux.x), std::fabs(v_aux.y));
			if (d_aux > d_max) { d_max = d_aux; v_max = v_aux; t_max = t; }
		}
		if (t_max)
			gameObject->onCollision(t_max->getCollider(), v_max);
	#else
		for (Tile* t : tileset) {
			Vector2f d = gameObject->getCollider().collide(t->getCollider());
			Vector2f v = gameObject->getSpeed();
			if (d.x * v.x > 0) d.x = 0;
			if (d.y * v.y > 0) d.y = 0;
			if (d == Vector2f(0, 0))
				continue;
			gameObject->onCollision(t->getCollider(), d);
		}
	#endif
	//*/
}
