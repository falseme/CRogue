#pragma once

#include "GameObject.h"
#include <item/Item.h>

class Entity :public GameObject {
public:
	static const enum state { idle, run, attack, stunned, heal, dead };

	Entity(Vector2f pos, string name, vector<Animation> anim, BoxCollider collider, int h, int mh, int d, float speed, int attackDistance, float cooldownLimit);

	void update() override;

	void setHealth(float h);
	int getHealth();
	int getMaxHealth();
	void setDamage(float d);
	int getDamage();

	void attackEntity(Entity* en);
	void moveTo(Vector2f target);
	void onCollision(BoxCollider other, Vector2f delta) override;

	void playStateAnimation();
	state getSelfState() const;

	void addItem(Item* i);
	Item* getItem(string name);
	void removeItem(Item* i);

protected:
	int health;
	int maxHealth;
	int damage;
	int attackDistance;
	float cooldown, cooldownLimit;

	state selfState;

	float sp; // speed vector mod
	Vector2f speed;

	list<Item*> inventory;
	void drawInventory(RWindow* render, bool background);
	void drawCooldown(RWindow* render);

	Entity* murderer;
};

