#include "Entity.h"

#include <util/Mathv.h>
#include <util/Timef.h>
#include <scene/SceneManager.h>

const string Entity::HEALTH_POTION_ID = "health";
const string Entity::HEALTH_POTION_SMALL_ID = "health_small";
const string Entity::KEY_ID = "key";

Entity::Entity(Vector2f pos, string name, vector<Animation> anim, BoxCollider collider, int h, int mh, int d, float speed, int attackDistance, float cooldownLimit) : GameObject(pos, name, anim, collider) {
	health = h;
	maxHealth = mh;
	damage = d;
	selfState = idle;
	sp = speed;
	this->attackDistance = attackDistance;
	this->cooldown = cooldownLimit;
	this->cooldownLimit = cooldownLimit;
	murderer = nullptr;
}

void Entity::setHealth(float h) {
	health = h;
}

int Entity::getHealth() {
	return health;
}

int Entity::getMaxHealth() {
	return maxHealth;
}

void Entity::setDamage(float d) {
	damage = d;
}

int Entity::getDamage() {
	return damage;
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

	if (currentAnimation != selfState) {
		animations[currentAnimation].reset();
		currentAnimation = selfState;
	}

	animations[currentAnimation].play();
	sprite.setTexture(*animations[currentAnimation].getFrame());

}

Entity::state Entity::getSelfState() const {
	return selfState;
}

void Entity::addInventoryItem(string name) {
	inventory[name]++;
}

bool Entity::hasItem(string name) {
	return inventory[name] > 0;
}

void Entity::removeInventoryItem(string name) {
	inventory[name]--;
}

bool Entity::useHealthPotion() {

	if (hasItem(HEALTH_POTION_ID)) {
		removeInventoryItem(HEALTH_POTION_ID);
		health += 2;
		if (health > maxHealth)
			health = maxHealth;
		return true;
	}

	if (hasItem(HEALTH_POTION_SMALL_ID)) {
		removeInventoryItem(HEALTH_POTION_SMALL_ID);
		health += 1;
		if (health > maxHealth)
			health = maxHealth;
		return true;
	}

	return false;

}

void Entity::giveItems(Entity* en) {
	en->inventory[KEY_ID] += inventory[KEY_ID];
	en->inventory[HEALTH_POTION_ID] += inventory[HEALTH_POTION_ID];
	en->inventory[HEALTH_POTION_SMALL_ID] += inventory[HEALTH_POTION_SMALL_ID];
	inventory.clear();
}

void Entity::drawInventory(RWindow* render, bool background) {

	if (inventory.empty())
		return;

	float w = 8;
	int inventorySize = (inventory[KEY_ID] + inventory[HEALTH_POTION_ID] + inventory[HEALTH_POTION_SMALL_ID]);
	float x = pos.x - w * inventorySize / 2;
	float y = pos.y - sprite.getLocalBounds().height * 2 / 3;

	if (background) {
		RectangleShape rs(Vector2f(w * inventorySize, w));
		rs.setPosition(x, y);
		rs.setFillColor(Color(40, 20, 30, 100));
		render->draw(rs);
	}

	for (int i = 0; i < inventory[KEY_ID]; i++) {
		Sprite spr(*Assets::key);
		spr.setPosition(x, y);
		spr.setScale(0.5f, 0.5f);
		render->draw(spr);
		x += w;
	}

	for (int i = 0; i < inventory[HEALTH_POTION_ID]; i++) {
		Sprite spr(*Assets::healthPotion);
		spr.setPosition(x, y);
		spr.setScale(0.5f, 0.5f);
		render->draw(spr);
		x += w;
	}

	for (int i = 0; i < inventory[HEALTH_POTION_SMALL_ID]; i++) {
		Sprite spr(*Assets::healthPotion_small);
		spr.setPosition(x, y);
		spr.setScale(0.5f, 0.5f);
		render->draw(spr);
		x += w;
	}

}

void Entity::drawCooldown(RWindow* render) {

	if (cooldown >= cooldownLimit)
		return;

	int w = 15;
	int h = 3;
	float x = pos.x - w / 2.f;
	float y = pos.y - sprite.getLocalBounds().height * 2 / 3 + h * 2.6f;

	RectangleShape bg(Vector2f(w, h));
	bg.setOrigin(0, h / 2.f);
	bg.setPosition(x, y);
	bg.setFillColor(Color(50, 50, 50, 150));
	RectangleShape coolrs(Vector2f(w * cooldown / cooldownLimit, 1));
	coolrs.setOrigin(0, 0.5f);
	coolrs.setPosition(x + 1, y);
	coolrs.setFillColor(Color(200, 180, 190));

	render->draw(bg);
	render->draw(coolrs);

}
