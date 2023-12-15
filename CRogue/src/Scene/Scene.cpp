#include "Scene.h"

#include <util/Mathv.h>

Scene::Scene() {

}

Scene::~Scene() {
	for (GameObject* go : gameObjects)
		delete go;
	for (Tile* t : tileset)
		delete t;
}

void Scene::draw(RWindow* render) {

	render->setView(cameraView);

	for (Tile* t : tileset)
		t->draw(render);

	for (GameObject* go : gameObjects)
		go->draw(render);

}

void Scene::addGameObject(GameObject* go) {
	gameObjects.push_back(go);
}

void Scene::removeGameObject(GameObject* go) {

	gameObjects.remove(go);
	delete go;

}

GameObject* Scene::find(string name) {

	for (GameObject* go : gameObjects) {
		if (go->getName() == name)
			return go;
	}

	return nullptr;

}

list<GameObject*> Scene::findAt(string name, Vector2f pos, float range) {

	list<GameObject*> found;

	for (GameObject* go : gameObjects) {
		if (go->getName() == name && Mathv::distance(go->getPos(), pos) <= range)
			found.push_back(go);
	}

	return found;

}

void Scene::addTile(Tile* t) {
	tileset.push_back(t);
}

void Scene::cameraFollow(Vector2f target, float offset) {

	if (Mathv::distance(target, cameraView.getCenter()) > offset) {
		Vector2f delta = target - cameraView.getCenter();
		Mathv::normalizeAndScale(delta, offset);
		Vector2f vMove = target - cameraView.getCenter() - delta;
		cameraView.setCenter(cameraView.getCenter() + vMove);
	}

}

void Scene::setCameraView(View view) {
	cameraView = view;
}

View Scene::getCameraView() {
	return cameraView;
}

