#include "BoxCollider.h"

BoxCollider::BoxCollider() {
	pos = Vector2f(0, 0);
	size = Vector2f(0, 0);
}

BoxCollider::BoxCollider(Vector2f size) {
	this->size = size;
}

BoxCollider::BoxCollider(Vector2f pos, Vector2f size) : BoxCollider(size) {
	this->pos = pos;
}

/**
*
*/
bool BoxCollider::collide(BoxCollider box) {
	if (box.pos.x - box.size.x / 2 <= pos.x + size.x / 2 &&
		box.pos.x + box.size.x / 2 >= pos.x - size.x / 2 &&
		box.pos.y - box.size.y / 2 <= pos.y + size.y / 2 &&
		box.pos.y + box.size.y / 2 >= pos.y - size.y / 2)
		return true;
	return false;
}

void BoxCollider::setPos(Vector2f pos) {
	this->pos = pos;
}

Vector2f BoxCollider::getPos() {
	return pos;
}

Vector2f BoxCollider::getSize() {
	return size;
}

