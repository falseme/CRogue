#include "GameObject.h"

#include <iostream>
using namespace std;

GameObject::GameObject() {

}

GameObject::GameObject(Vector2f pos) {
	this->pos = pos;
	sprite.setPosition(pos);
}

GameObject::GameObject(Vector2f pos, Animation anim) : GameObject(pos) {
	animation = anim;
	sprite.setTexture(*animation.getFrame());
	sprite.setOrigin(Vector2f(anim.getFrame()->getSize().x / 2, anim.getFrame()->getSize().y / 2));
}

GameObject::GameObject(Vector2f pos, Animation anim, BoxCollider collider) : GameObject(pos, anim) {
	this->collider = collider;
	this->collider.setPos(pos);
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
