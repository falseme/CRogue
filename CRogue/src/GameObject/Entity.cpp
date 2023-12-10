#include "Entity.h"

Entity::Entity(Vector2f pos, std::string name, vector<Animation> anim, BoxCollider collider, float h, float d) : GameObject(pos, name, anim, collider) {
	SetHealth(h);
	SetDamage(d);
	selfState = idle;
}
float Entity::GetHealth() {
	return health;
}
void Entity::SetHealth(float h) {
	health = h;
}
void Entity::Attacked(float d) {
	health -= d;
}
float Entity::GetDamage() {
	return damage;
}
void Entity::SetDamage(float d) {
	damage = d;
}

void Entity::update() {}
void Entity::onCollision(BoxCollider other, Vector2f delta){}

void Entity::playStateAnimation() {

	if (currentAnimation != selfState) { // idle = 0 // run = 1 // attack = 2 //
		animations[currentAnimation].reset();
		currentAnimation = selfState;
	}

	animations[currentAnimation].play();
	sprite.setTexture(*animations[currentAnimation].getFrame());

}

Entity::state Entity::getSelfState() {
	return selfState;
}

void Entity::setSelfState(Entity::state s) {
	selfState = s;
}
