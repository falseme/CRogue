#pragma once

#include <SFML/Graphics.hpp>
#include "../UI/RWindow.h"

using namespace sf;

class GameObject {
protected:
	Vector2f pos;
	Sprite sprite;
public:
	GameObject();
	GameObject(Vector2f pos);
	GameObject(Vector2f pos, Texture* tex);

	virtual void update() = 0;
	void draw(RWindow* render);

	void move(Vector2f delta);
};

