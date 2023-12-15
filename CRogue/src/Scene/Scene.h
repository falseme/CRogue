#pragma once

#include <list>

#include <GameObject/GameObject.h>
#include <UI/RWindow.h>
#include <Scene/Tile.h>
#include <assets/Assets.h>

using namespace std;

/**
* An Abstract Scene class
*/
class Scene {
protected:
	View cameraView;
	list<GameObject*> gameObjects;
	list<Tile*> tileset;
public:
	Scene();
	~Scene();

	virtual void init() = 0;
	virtual void update() = 0;
	void draw(RWindow* render);

	void addGameObject(GameObject* go);
	void removeGameObject(GameObject* go);
	GameObject* find(string name);
	list<GameObject*> findAt(string name, Vector2f pos, float range = 0);

	virtual void loadScene() = 0;
	void addTile(Tile* t);

	void cameraFollow(Vector2f target, float offset);
	void setCameraView(View view);
	View getCameraView();
};

