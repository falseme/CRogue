#include "LevelScene.h"

#include <fstream>
#include <sstream>
#include <time.h>

#include <gameObject/Player.h>
#include <gameObject/Enemy.h>
#include <gameObject/Door.h>
#include <gameObject/Ladder.h>
#include <item/HealthPotion.h>

LevelScene::LevelScene(int level, float accCamZoom) : Scene(accCamZoom) {
	this->level = level;
}

void LevelScene::update() {

	if (!zoomOut(0.32f, 0.8f)) {
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
				loadGameObject(tileKey.back(), px, py);
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

	// GIVE KEYS TO ENEMIES
	vector<GameObject*> enemies = findAll("enemy");
	int n = rand() % enemies.size();
	((Enemy*)enemies[n])->addItem(new Item(Assets::key, "key"));

	// GIVE HEAL POTIONS TO ENEMIES
	for (int i = 0; i < enemies.size(); i++) {
		int healProbability = rand() % 100;
		if (healProbability < 10)
			((Enemy*)enemies[i])->addItem(new HealthPotion(Assets::healthPotion, "health_potion", 2));
		else if (healProbability < 35) // 25% (35-10)
			((Enemy*)enemies[i])->addItem(new HealthPotion(Assets::healthPotion_small, "health_potion", 1));
	}

}

void LevelScene::loadGameObject(char key, int x, int y) {

	switch (key) {
	case '0':
		addGameObject(new Player(Vector2f(x, y), 10, 2, 1.5f));
		break;
	case '1':
		addGameObject(new Enemy(Vector2f(x, y), { Animation(1.2f, Assets::skelyIdle), Animation(0.6f, Assets::skelyRun), Animation(0.6f, Assets::skelyAttack), Animation(0.5f, Assets::skelyStunned), Animation(0.5f, Assets::skelyHeal), Animation(Assets::skelyDead) }, 8, 2, 0.8f, 20, 90, 1.1f));
		break;
	case '2':
		addGameObject(new Enemy(Vector2f(x, y), { Animation(1.2f, Assets::skelyIdleSW), Animation(0.6f, Assets::skelyRunSW), Animation(0.55f, Assets::skelyAttackSW), Animation(0.5f, Assets::skelyStunnedSW), Animation(0.5f, Assets::skelyHealSW), Animation(Assets::skelyDeadSW) }, 6, 1, 0.9f, 18, 90, 0.95f));
		break;
	case '3':
		addGameObject(new Enemy(Vector2f(x, y), { Animation(1.2f, Assets::skelyIdle_pow), Animation(0.6f, Assets::skelyRun_pow), Animation(0.55f, Assets::skelyAttack_pow), Animation(0.5f, Assets::skelyStunned_pow), Animation(0.5f, Assets::skelyHeal_pow), Animation(Assets::skelyDead_pow) }, 12, 3, 1.05f, 20, 100, 0.85));
		break;
	case '4':
		addGameObject(new Enemy(Vector2f(x, y), { Animation(1.2f, Assets::skelyIdleSW_pow), Animation(0.6f, Assets::skelyRunSW_pow), Animation(0.5f, Assets::skelyAttackSW_pow), Animation(0.5f, Assets::skelyStunnedSW_pow), Animation(0.5f, Assets::skelyHealSW_pow), Animation(Assets::skelyDeadSW_pow) }, 10, 2, 1.12f, 20, 100, 0.65f));
		break;
	case '6':
		addGameObject(new Door(Vector2f(x + 8, y)));
		break;
	case '7':
		addGameObject(new Ladder(Vector2f(x, y)));
		break;
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
