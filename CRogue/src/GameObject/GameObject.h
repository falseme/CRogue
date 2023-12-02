#pragma once

#include <SFML/Graphics.hpp>
#include "../UI/RWindow.h"
#include "../animation/Animation.h"
#include "../collision/BoxCollider.h"

using namespace sf;

class GameObject {
protected:
	Vector2f pos;
	Sprite sprite;
	Animation animation;
	BoxCollider collider;
public:
	GameObject();
	GameObject(Vector2f pos);
	GameObject(Vector2f pos, Animation anim);
	GameObject(Vector2f pos, Animation anim, BoxCollider collider);

	virtual void update() = 0;
	void draw(RWindow* render);

	void move(Vector2f delta);
	virtual void onCollision(BoxCollider other) = 0;

	BoxCollider getCollider();
};

