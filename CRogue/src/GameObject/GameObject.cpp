#include "GameObject.h"

#include <iostream>
using namespace std;

GameObject::GameObject() {

}

GameObject::GameObject(Vector2f pos) {
	this->pos = pos;
}

GameObject::GameObject(Vector2f pos, Animation anim) {
	this->pos = pos;
	animation = anim;
	sprite.setTexture(*animation.getFrame());
}

void GameObject::draw(RWindow* render) {
	render->draw(sprite);
}

void GameObject::move(Vector2f delta) {
	pos.x += delta.x;
	pos.y += delta.y;
}
