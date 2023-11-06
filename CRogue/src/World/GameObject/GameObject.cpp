#include "GameObject.h"

GameObject::GameObject() {

}

GameObject::GameObject(Vector2f pos) {
	this->pos = pos;
}

void GameObject::draw() {

}

void GameObject::move(Vector2f delta) {
	pos.x += delta.x;
	pos.y += delta.y;
}
