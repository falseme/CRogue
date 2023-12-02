#include "Scene.h"

#include <fstream>
#include <sstream>

Scene::Scene() {

}

Scene::~Scene() {
	for (GameObject* go : gameObjects)
		delete go;
	for (Tile* t : tileset)
		delete t;
}

void Scene::update() {

}

void Scene::draw(RWindow* render) {

	for (Tile* t : tileset)
		t->draw(render);

	for (GameObject* go : gameObjects)
		go->draw(render);

}

void Scene::addGameObject(GameObject* go) {
	gameObjects.push_back(go);
}

void Scene::removeGameObject(GameObject* go) {

	int index = 0;
	for (GameObject* g : gameObjects) {
		if (g == go)
			break;
		index++;
	}

	list<GameObject*>::iterator it = gameObjects.begin();
	advance(it, index);

	if (it == gameObjects.end())
		return;
	it = gameObjects.erase(it);

}
void Scene::addTile(Tile* t) {
	tileset.push_back(t);
}

void Scene::loadLevel(int level) {

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
