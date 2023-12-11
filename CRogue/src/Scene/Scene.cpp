#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {
	for (GameObject* go : gameObjects)
		delete go;
	for (Tile* t : tileset)
		delete t;
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

