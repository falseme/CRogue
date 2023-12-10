#include "BoxCollider.h"

BoxCollider::BoxCollider() {
	
}

BoxCollider::BoxCollider(Vector2f size) {
	this->size = size;
}

BoxCollider::BoxCollider(Vector2f size, Vector2f offset) : BoxCollider(size) {
	this->offset = offset;
}

BoxCollider::BoxCollider(Vector2f size, Vector2f offset, Vector2f pos) : BoxCollider(size, offset) {
	this->pos = pos;
}

/**
*
*/
Vector2f BoxCollider::collide(BoxCollider other) {

	if (pos.x + size.x / 2 < other.pos.x - other.size.x / 2) // on the left
		return { 0,0 };
	if (pos.x - size.x / 2 > other.pos.x + other.size.x / 2) // on the right
		return { 0,0 };
	if (pos.y + size.y / 2 < other.pos.y - other.size.y / 2) // above
		return { 0,0 };
	if (pos.y - size.y / 2 > other.pos.y + other.size.y / 2) // bellow
		return { 0,0 };

	float dx, dy;

	if (pos.x < other.pos.x) // left
		dx = (other.pos.x - other.size.x / 2) - (pos.x + size.x / 2);
	else // right
		dx = (other.pos.x + other.size.x / 2) - (pos.x - size.x / 2);

	if (pos.y < other.pos.y) // above
		dy = (other.pos.y - other.size.y / 2) - (pos.y + size.y / 2);
	else // bellow
		dy = (other.pos.y + other.size.y / 2) - (pos.y - size.y / 2);

	return { dx,dy };

}

void BoxCollider::setPos(Vector2f pos) {
	this->pos = pos + offset;
}

Vector2f BoxCollider::getPos() {
	return pos;
}

Vector2f BoxCollider::getSize() {
	return size;
}

