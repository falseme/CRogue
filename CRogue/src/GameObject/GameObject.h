#pragma once

#include <list>
#include <SFML/Graphics.hpp>

#include <ui/RWindow.h>
#include <animation/Animation.h>
#include <collision/BoxCollider.h>

class GameObject {
protected:
	string name;
	Vector2f pos;
	Sprite sprite;
	vector<Animation> animations;
	int currentAnimation;
	BoxCollider collider;
public:
	GameObject();
	GameObject(Vector2f pos, string name);
	GameObject(Vector2f pos, string name, vector<Animation> anim);
	GameObject(Vector2f pos, string name, vector<Animation> anim, BoxCollider collider);

	virtual void update() = 0;
	virtual void draw(RWindow* render);

	void move(Vector2f delta);
	virtual void onCollision(BoxCollider other, Vector2f delta) = 0;

	BoxCollider getCollider();
	Vector2f getPos();
	string getName();

	bool comp(GameObject* g);
};

