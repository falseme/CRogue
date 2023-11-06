#include "GameObject.h"

#include <iostream>
using namespace std;

GameObject::GameObject() {

}

GameObject::GameObject(Vector2f pos) {
	this->pos = pos;
}

void GameObject::draw(RWindow* render) {
	cout << "draw";
}

void GameObject::move(Vector2f delta) {
	pos.x += delta.x;
	pos.y += delta.y;
}
