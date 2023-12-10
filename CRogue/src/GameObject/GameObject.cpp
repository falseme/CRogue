#include "GameObject.h"

list<GameObject*>* GameObject::sceneGameObjects = NULL;

GameObject::GameObject() {
	currentAnimation = 0;
}

GameObject::GameObject(Vector2f pos, std::string name) {
	this->pos = pos;
	this->name = name;
	sprite.setPosition(pos);
	currentAnimation = 0;
}

GameObject::GameObject(Vector2f pos, std::string name, vector<Animation> anim) : GameObject(pos, name) {
	animations = anim;
	sprite.setTexture(*animations[currentAnimation].getFrame());
	sprite.setOrigin(Vector2f(animations[currentAnimation].getFrame()->getSize().x / 2.f, animations[currentAnimation].getFrame()->getSize().y / 2.f));
}

GameObject::GameObject(Vector2f pos, std::string name, vector<Animation> anim, BoxCollider collider) : GameObject(pos, name, anim) {
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

void GameObject::setGameObjectCurrentList(list<GameObject*>* currentList) {

	sceneGameObjects = currentList;

}

GameObject* GameObject::find(std::string name) {

	for (GameObject* go : *sceneGameObjects) {
		if (go->name == name)
			return go;
	}

	return NULL;

}
