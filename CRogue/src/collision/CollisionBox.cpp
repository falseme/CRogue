#include "CollisionBox.h"

CollisionBox::CollisionBox() {
	pos = Vector2f(0, 0);
	size = Vector2f(0, 0);
}

CollisionBox::CollisionBox(Vector2f size) {
	this->size = size;
}

CollisionBox::CollisionBox(Vector2f pos, Vector2f size) : CollisionBox(pos) {
	this->size = size;
}

/**
* 
*/
bool CollisionBox::collide(CollisionBox box) {
	if (box.pos.x - box.size.x / 2 <= pos.x + size.x / 2 &&
		box.pos.x + box.size.x/2 >= pos.x - size.x/2 &&
		box.pos.y - box.size.y/2 <= pos.y + size.y/2 &&
		box.pos.y + box.size.y/2 >= pos.y - size.y/2)
		return true;
	return false;
}

void CollisionBox::setPos(Vector2f pos) {
	this->pos = pos;
}