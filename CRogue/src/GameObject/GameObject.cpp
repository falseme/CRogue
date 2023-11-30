#include "GameObject.h"

#include <iostream>
using namespace std;

GameObject::GameObject() {

}

GameObject::GameObject(Vector2f pos) {
	this->pos = pos;
	sprite.setOrigin(Vector2f(0.5f, 0.5f));
	sprite.setPosition(pos);
}

GameObject::GameObject(Vector2f pos, Animation anim) : GameObject(pos) {
	animation = anim;
	sprite.setTexture(*animation.getFrame());
}

GameObject::GameObject(Vector2f pos, Animation anim, BoxCollider collider) : GameObject(pos, anim) {
	sprite.setTexture(*animation.getFrame());
	this->collider = collider;
	collider.setPos(pos);
}

void GameObject::draw(RWindow* render) {
	render->draw(sprite);
}

void GameObject::move(Vector2f delta) {
	pos.x += delta.x;
	pos.y += delta.y;
	sprite.setPosition(pos);
	collider.setPos(pos);
}

BoxCollider GameObject::getCollider() {
	return collider;
}
