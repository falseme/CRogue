#include "Scene.h"

#include <util/Mathv.h>
#include <util/Timef.h>

Scene::Scene() {
	camZoom = 1;
}

Scene::Scene(float accCamZoom) {
	camZoom = accCamZoom;
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

	GUIPanel.draw(render);

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

vector<GameObject*> Scene::findAll(string name) {

	vector<GameObject*> found;

	for (GameObject* go : gameObjects) {
		if (go->getName() == name)
			found.push_back(go);
	}

	return found;

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

	if (Mathv::distance(target, cameraView.getCenter()) < offset)
		return;

	Vector2f previousPos = cameraView.getCenter();
	Vector2f delta = target - cameraView.getCenter();
	Mathv::normalizeAndScale(delta, offset);
	cameraView.setCenter(target - delta);

	Vector2f GUIMove = cameraView.getCenter() - previousPos;
	GUIPanel.move(GUIMove);

}

bool Scene::zoomIn(float zoom, float step) {

	if (camZoom <= zoom)
		return true;

	step *= Timef::deltaTime();

	step = 1 - step;
	camZoom *= step;
	cameraView.zoom(step);

	return false;

}

bool Scene::zoomOut(float zoom, float step) {

	if (camZoom >= zoom)
		return true;

	step *= Timef::deltaTime();

	step = 1 + step;
	camZoom *= step;
	cameraView.zoom(step);

	return false;

}

void Scene::setCameraView(View view) {
	cameraView = view;
	cameraView.zoom(camZoom);
}

View Scene::getCameraView() {
	return cameraView;
}

float Scene::getAccCamZoom() {
	return camZoom;
}

