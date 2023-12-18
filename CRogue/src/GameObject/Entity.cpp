#include "Entity.h"

#include <util/Mathv.h>
#include <util/Timef.h>
#include <scene/SceneManager.h>

Entity::Entity(Vector2f pos, string name, vector<Animation> anim, BoxCollider collider, float h, float d, float speed, int attackDistance) : GameObject(pos, name, anim, collider) {
	health = h;
	damage = d;
	selfState = idle;
	sp = speed;
	this->attackDistance = attackDistance;
	murderer = nullptr;
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
	if (en->selfState == stunned || en->selfState == dead || en->selfState == heal)
		return;
	if (Mathv::distance(pos, en->pos) < attackDistance) {
		en->health -= damage;
		en->selfState = stunned;
		en->speed = en->pos - pos;
		Mathv::normalizeAndScale(en->speed, 0.05f * Timef::deltaTimeFactor());
	}
	if (en->health <= 0)
		en->murderer = this;
}

void Entity::moveTo(Vector2f target) {

	speed = target - pos;
	Mathv::normalizeAndScale(speed, sp * Timef::deltaTimeFactor());

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

void Entity::addItem(Item* i) {
	inventory.push_back(i);
}

Item* Entity::getItem(string name) {

	for (Item* i : this->inventory) {
		if (i->getName() == name)
			return i;
	}

	return nullptr;

}

void Entity::removeItem(Item* i) {
	inventory.remove(i);
	delete i;
}

void Entity::drawInventory(RWindow* render, bool background) {

	if (inventory.empty())
		return;

	float w = inventory.front()->getSprite().getLocalBounds().width * inventory.front()->getSprite().getScale().x;
	float x = pos.x - w * inventory.size() / 2;
	float y = pos.y - sprite.getLocalBounds().height * 2 / 3;

	if (background) {
		RectangleShape rs(Vector2f(w * inventory.size(), w));
		rs.setPosition(x, y);
		rs.setFillColor(Color(40, 20, 30, 100));
		render->draw(rs);
	}

	for (Item* i : inventory) {
		i->getSprite().setPosition(x, y);
		render->draw(i->getSprite());
		x += w;
	}

}
