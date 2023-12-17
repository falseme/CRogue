#pragma once

#include <list>

#include <gameObject/GameObject.h>
#include <ui/RWindow.h>
#include <scene/Tile.h>
#include <assets/Assets.h>

using namespace std;

/**
* An Abstract Scene class
*/
class Scene {
private:
	View cameraView;
	float camZoom; // zoom accumulated factor // zoom(1.05) + zoom(1.05) = zoom(1.1025)
protected:
	list<GameObject*> gameObjects;
	list<Tile*> tileset;
public:
	Scene();
	Scene(float accCamZoom);
	~Scene();

	virtual void update() = 0;
	void draw(RWindow* render);

	void addGameObject(GameObject* go);
	void removeGameObject(GameObject* go);
	GameObject* find(string name);
	vector<GameObject*> findAll(string name);
	list<GameObject*> findAt(string name, Vector2f pos, float range = 0);

	virtual void loadScene() = 0;
	void addTile(Tile* t);

	void cameraFollow(Vector2f target, float offset = 0);
	bool zoomIn(float zoom, float step);
	bool zoomOut(float zoom, float step);
	void setCameraView(View view);
	View getCameraView();
	float getAccCamZoom();
};

