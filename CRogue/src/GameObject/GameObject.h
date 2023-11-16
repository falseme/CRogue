#pragma once

#include <SFML/Graphics.hpp>
#include "../UI/RWindow.h"
#include "../animation/Animation.h"

using namespace sf;

class GameObject {
protected:
	Vector2f pos;
	Sprite sprite;
	Animation animation;
public:
	GameObject();
	GameObject(Vector2f pos);
	GameObject(Vector2f pos, Animation anim);

	virtual void update() = 0;
	void draw(RWindow* render);

	void move(Vector2f delta);
};

