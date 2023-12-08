#pragma once


#include <SFML/Graphics.hpp>

using namespace sf;

class BoxCollider {
private:
	Vector2f pos, size;
public:
	BoxCollider();
	BoxCollider(Vector2f size);
	BoxCollider(Vector2f pos, Vector2f size);
	Vector2f collide(BoxCollider box);
	void setPos(Vector2f pos);
	Vector2f getSize();
	Vector2f getPos();
};

