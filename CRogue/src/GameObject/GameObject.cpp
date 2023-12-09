#include "GameObject.h"

GameObject::GameObject() {
	currentAnimation = 0;
}

GameObject::GameObject(Vector2f pos) {
	this->pos = pos;
	sprite.setPosition(pos);
	currentAnimation = 0;
}

GameObject::GameObject(Vector2f pos, vector<Animation> anim) : GameObject(pos) {
	animations = anim;
	sprite.setTexture(*animations[currentAnimation].getFrame());
	sprite.setOrigin(Vector2f(animations[currentAnimation].getFrame()->getSize().x / 2.f, animations[currentAnimation].getFrame()->getSize().y / 2.f));
}

GameObject::GameObject(Vector2f pos, vector<Animation> anim, BoxCollider collider) : GameObject(pos, anim) {
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
