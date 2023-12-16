#include "GameObject.h"

#include <util/Mathv.h>

GameObject::GameObject() {
	currentAnimation = 0;
}

GameObject::GameObject(Vector2f pos, string name) {
	this->pos = pos;
	this->name = name;
	sprite.setPosition(pos);
	currentAnimation = 0;
}

GameObject::GameObject(Vector2f pos, string name, vector<Animation> anim) : GameObject(pos, name) {
	animations = anim;
	sprite.setTexture(*animations[currentAnimation].getFrame());
	sprite.setOrigin(Vector2f(animations[currentAnimation].getFrame()->getSize().x / 2.f, animations[currentAnimation].getFrame()->getSize().y / 2.f));
}

GameObject::GameObject(Vector2f pos, string name, vector<Animation> anim, BoxCollider collider) : GameObject(pos, name, anim) {
	this->collider = collider;
	this->collider.setPos(pos);
}

void GameObject::draw(RWindow* render) {
	render->draw(sprite);
	//*// DRAW BOX COLLIDER
	RectangleShape rs(collider.getSize());
	rs.setOrigin(Vector2f(collider.getSize().x / 2, collider.getSize().y / 2));
	rs.setPosition(collider.getPos());
	rs.setFillColor(Color::Green);
	render->draw(rs);
	//*/
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

Vector2f GameObject::getPos() {
	return pos;
}

string GameObject::getName() {
	return name;
}

bool GameObject::comp(GameObject* g) {
	if (g->pos.y > pos.y)
		return 1;
	return 0;
}
