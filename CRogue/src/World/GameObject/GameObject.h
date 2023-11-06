#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class GameObject {
	Vector2f pos;
public:
	GameObject();
	GameObject(Vector2f pos);

	virtual void update() = 0;
	void draw();

	void move(Vector2f delta);
};

