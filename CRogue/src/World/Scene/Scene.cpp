#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {
	for (GameObject* go : gameObjects)
		delete go;
}

void Scene::update() {

}

void Scene::draw(RWindow* render) {
	/*for (list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); it++) {
		GameObject *go = *it;
		go->draw(render);
	}*/
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