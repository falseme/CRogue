#pragma once

#include <list>
#include <SFML/Graphics.hpp>

#include "../UI/RWindow.h"
#include "../animation/Animation.h"
#include "../collision/BoxCollider.h"

using namespace sf;

class GameObject {
protected:
	Vector2f pos;
	Sprite sprite;
	vector<Animation> animations;
	int currentAnimation;
	BoxCollider collider;
public:
	GameObject();
	GameObject(Vector2f pos);
	GameObject(Vector2f pos, vector<Animation> anim);
	GameObject(Vector2f pos, vector<Animation> anim, BoxCollider collider);

	virtual void update() = 0;
	void draw(RWindow* render);

	void move(Vector2f delta);
	virtual void onCollision(BoxCollider other, Vector2f delta) = 0;

	BoxCollider getCollider();
};

