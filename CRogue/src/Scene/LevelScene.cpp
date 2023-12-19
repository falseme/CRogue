#include "LevelScene.h"

#include <fstream>
#include <sstream>
#include <time.h>

#include <gameObject/Player.h>
#include <gameObject/Enemy.h>
#include <gameObject/Door.h>
#include <gameObject/Ladder.h>
#include <item/HealthPotion.h>
#include <scene/SceneManager.h>

LevelScene::LevelScene(int level, float accCamZoom, int playerHealth) : Scene(accCamZoom) {
	this->level = level;
	for (int i = 0; i < 4; i++) {
		SpriteImage* si = new SpriteImage(Assets::heart, Vector2f(275 + 12 * i, 210), Vector2f(0.75f, 0.75f), Vector2f(0, 0));
		GUIHealth.push_back(si);
		GUIPanel.addComponent(si);
	}
	if (level != 1)
		updateGUIHealth(playerHealth);
	else
		this->playerHealth = Player::MAX_HEALTH;
}

void LevelScene::update(Vector2f mousePosition) {

	if (Keyboard::isKeyPressed(Keyboard::Escape))
		SceneManager::pauseGame();

	GUIPanel.update(mousePosition);

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

	//GAMELEVEL

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

			if (tileKey.front() == '&')
				tileKey = loadGameObject(tileKey.back(), px, py);

			bool collider = tileKey.front() == '#' ? true : false;
			if (Assets::tilemap[tileKey].size() == 0) {
				px += 16;
				continue;
			}
			int texIndex = rand() % Assets::tilemap[tileKey].size();

			addTile(new Tile(Vector2f(px, py), Assets::tilemap[tileKey][texIndex], collider));
			px += 16;

		}

		py += 16;

	}

	levelFile.close();

	// GIVE KEYS TO ENEMIES
	vector<GameObject*> enemies = findAll("enemy");
	if (enemies.empty())
		return;
	int n = rand() % enemies.size();
	((Enemy*)enemies[n])->addItem(new Item(Assets::key, "key"));

	// GIVE HEAL POTIONS TO ENEMIES
	for (int i = 0; i < enemies.size(); i++) {
		int healProbability = rand() % 100;
		if (healProbability < 10)
			((Enemy*)enemies[i])->addItem(new HealthPotion(Assets::healthPotion, "health_potion", 2));
		else if (healProbability < 90) // 25% (35-10)
			((Enemy*)enemies[i])->addItem(new HealthPotion(Assets::healthPotion_small, "health_potion", 1));
	}

}

string LevelScene::loadGameObject(char key, int x, int y) {

	string newTileKey;
	SceneObject* so = nullptr;

	switch (key) {
	case '0':
		addGameObject(new Player(Vector2f(x, y), playerHealth, 2, 1.5f));
		cameraFollow(Vector2f(x, y));
		newTileKey = "O0";
		break;
	case '1':
		addGameObject(new Enemy(Vector2f(x, y), { Animation(1.2f, Assets::skelyIdle), Animation(0.6f, Assets::skelyRun), Animation(0.6f, Assets::skelyAttack), Animation(0.5f, Assets::skelyStunned), Animation(0.5f, Assets::skelyHeal), Animation(Assets::skelyDead) }, 8, 2, 0.8f, 20, 90, 1.1f));
		newTileKey = "O0";
		break;
	case '2':
		addGameObject(new Enemy(Vector2f(x, y), { Animation(1.2f, Assets::skelyIdleSW), Animation(0.6f, Assets::skelyRunSW), Animation(0.55f, Assets::skelyAttackSW), Animation(0.5f, Assets::skelyStunnedSW), Animation(0.5f, Assets::skelyHealSW), Animation(Assets::skelyDeadSW) }, 6, 1, 0.9f, 18, 90, 0.95f));
		newTileKey = "O0";
		break;
	case '3':
		addGameObject(new Enemy(Vector2f(x, y), { Animation(1.2f, Assets::skelyIdle_pow), Animation(0.6f, Assets::skelyRun_pow), Animation(0.55f, Assets::skelyAttack_pow), Animation(0.5f, Assets::skelyStunned_pow), Animation(0.5f, Assets::skelyHeal_pow), Animation(Assets::skelyDead_pow) }, 12, 3, 1.05f, 20, 100, 0.85));
		newTileKey = "O0";
		break;
	case '4':
		addGameObject(new Enemy(Vector2f(x, y), { Animation(1.2f, Assets::skelyIdleSW_pow), Animation(0.6f, Assets::skelyRunSW_pow), Animation(0.5f, Assets::skelyAttackSW_pow), Animation(0.5f, Assets::skelyStunnedSW_pow), Animation(0.5f, Assets::skelyHealSW_pow), Animation(Assets::skelyDeadSW_pow) }, 10, 2, 1.12f, 20, 100, 0.75f));
		newTileKey = "O0";
		break;
	case '6':
		addGameObject(new Door(Vector2f(x + 8, y)));
		newTileKey = "O0";
		break;
	case '7':
		addGameObject(new SceneObject(Vector2f(x, y), { Animation(0.8f, Assets::flag) }, BoxCollider()));
		newTileKey = "#0";
		break;
	case '8':
		addGameObject(new SceneObject(Vector2f(x, y), { Animation(0.7f, Assets::torch) }, BoxCollider()));
		newTileKey = "#0";
		break;
	case '9':
		addGameObject(new SceneObject(Vector2f(x, y), { Animation(0.7f, Assets::torch_side) }, BoxCollider()));
		newTileKey = "O7";
		break;
	case 'A':
		so = new SceneObject(Vector2f(x, y), { Animation(0.7f, Assets::torch_side) }, BoxCollider());
		so->getSprite().setScale(-1, 1);
		addGameObject(so);
		newTileKey = "O8";
		break;
	case 'B':
		addGameObject(new Ladder(Vector2f(x, y)));
		newTileKey = "O0";
		break;
	}

	return newTileKey;

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

void LevelScene::updateGUIHealth(int health) {

	int whole = health / 2;
	for (int i = 0; i < whole; i++)
		GUIHealth[i]->setTexture(Assets::heart);

	if (whole <= GUIHealth.size())
		for (int i = whole; i < GUIHealth.size(); i++)
			GUIHealth[i]->setTexture(Assets::heart_empty);

	int half = health % 2;
	if (half != 0)
		GUIHealth[whole]->setTexture(Assets::heart_half);

	playerHealth = health;

}

int LevelScene::getPlayerHealth() {
	return playerHealth;
}
