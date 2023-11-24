#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class CollisionBox {
private:
	Vector2f pos, size;
public:
	CollisionBox();
	CollisionBox(Vector2f size);
	CollisionBox(Vector2f pos, Vector2f size);
	bool collide(CollisionBox box);
	void setPos(Vector2f pos);
};

