#include "Entity.h"

#include "../util/Mathv.h"

Entity::Entity(Vector2f pos, std::string name, vector<Animation> anim, BoxCollider collider, float h, float d, float speed) : GameObject(pos, name, anim, collider) {
	SetHealth(h);
	SetDamage(d);
	selfState = idle;
	sp = speed;
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

void Entity::moveTo(Vector2f target) {

	Vector2f delta = target - pos;
	Mathv::normalizeAndScale(delta, sp);

	speed = delta;
	move(delta);

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
