#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class BoxCollider {
private:
	Vector2f pos, size, offset;
public:
	BoxCollider();
	BoxCollider(Vector2f size);
	BoxCollider(Vector2f size, Vector2f offset);
	BoxCollider(Vector2f size, Vector2f offset, Vector2f pos);
	Vector2f collide(BoxCollider box);
	void setPos(Vector2f pos);
	Vector2f getPos();
	void setSize(Vector2f size);
	Vector2f getSize();
	bool operator==(BoxCollider& other);
	bool operator!=(BoxCollider& other);
};

