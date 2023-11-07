#pragma once

#include <SFML/Graphics.hpp>
#include "../UI/RWindow.h"

using namespace sf;

class GameObject {
	Vector2f pos;
public:
	GameObject();
	GameObject(Vector2f pos);

	virtual void update() = 0;
	void draw(RWindow* render);

	void move(Vector2f delta);
};

