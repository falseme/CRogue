#include "Entity.h"

#include <util/Mathv.h>
#include <scene/SceneManager.h>

Entity::Entity(Vector2f pos, string name, vector<Animation> anim, BoxCollider collider, float h, float d, float speed, int attackDistance) : GameObject(pos, name, anim, collider) {
	health = h;
	damage = d;
	selfState = idle;
	sp = speed;
	this->attackDistance = attackDistance;
}

float Entity::GetHealth() {
	return health;
}
void Entity::SetHealth(float h) {
	health = h;
}

float Entity::GetDamage() {
	return damage;
}
void Entity::SetDamage(float d) {
	damage = d;
}

void Entity::attackEntity(Entity* en) {
	if (en->selfState == stunned || en->selfState == dead)
		return;
	if (Mathv::distance(pos, en->pos) < attackDistance) {
		en->health -= damage;
		en->selfState = stunned;
		en->speed = en->pos - pos;
		Mathv::normalizeAndScale(en->speed, 0.05f);
	}
	if (en->health <= 0) {
		en->selfState = dead;
		en->collider = BoxCollider();
		en->speed = { 0,0 };
	}
}

void Entity::moveTo(Vector2f target) {

	speed = target - pos;
	Mathv::normalizeAndScale(speed, sp);

	move(speed);

}

void Entity::update() {}

void Entity::onCollision(BoxCollider other, Vector2f delta) {

	Vector2f d = other.getPos() - collider.getPos();

	if (abs(d.x) > abs(d.y)) {
		move(Vector2f(delta.x, 0));
	}
	else if (abs(d.x) < abs(d.y)) {
		move(Vector2f(0, delta.y));
	}

}

void Entity::playStateAnimation() {

	if (currentAnimation != selfState) { // idle = 0 // run = 1 // attack = 2 //
		animations[currentAnimation].reset();
		currentAnimation = selfState;
	}

	animations[currentAnimation].play();
	sprite.setTexture(*animations[currentAnimation].getFrame());

}

Entity::state Entity::getSelfState() const {
	return selfState;
}
