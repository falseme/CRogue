#pragma once

#include <list>

#include "../GameObject/GameObject.h"
#include "../UI/RWindow.h"
#include "../Scene/Tile.h"
#include "../assets/Assets.h"

using namespace std;

/**
* An Abstract Scene class
*/
class Scene {
protected:
	list<GameObject*> gameObjects;
	list<Tile*> tileset;
public:
	Scene();
	~Scene();

	virtual void init() = 0;
	virtual void update();
	void draw(RWindow* render);

	void addGameObject(GameObject* go);
	void removeGameObject(GameObject* go);

	void loadLevel(int level);
	void addTile(Tile* t);
};

