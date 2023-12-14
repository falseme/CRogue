#include "GameObject.h"

#include "../util/Mathv.h"

list<GameObject*>* GameObject::sceneGameObjects = NULL;

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

void GameObject::setGameObjectCurrentList(list<GameObject*>* currentList) {

	sceneGameObjects = currentList;

}

GameObject* GameObject::find(string name) {

	for (GameObject* go : *sceneGameObjects) {
		if (go->name == name)
			return go;
	}

	return NULL;

}

list<GameObject*> GameObject::findRangeAt(string name, Vector2f pos, float range) {

	list<GameObject*> found;

	for (GameObject* go : *sceneGameObjects) {
		if (go->name == name && Mathv::distance(go->pos, pos) <= range)
			found.push_back(go);
	}

	return found;

}

void GameObject::erase(GameObject* go) {

	sceneGameObjects->remove(go);
	delete go;

}

bool GameObject::comp(GameObject* g) {
	if (g->pos.y > pos.y)
		return 1;
	return 0;
}
