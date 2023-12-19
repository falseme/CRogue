#pragma once

#include "GameObject.h"

class Entity : public GameObject {
public:
	static const enum state { idle, run, attack, stunned, heal, dead };
	static const string HEALTH_POTION_ID;
	static const string HEALTH_POTION_SMALL_ID;
	static const string KEY_ID;

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

	void addInventoryItem(string name);
	bool hasItem(string name);
	void removeInventoryItem(string name);
	bool useHealthPotion();
	void giveItems(Entity* en);

protected:
	int health;
	int maxHealth;
	int damage;
	int attackDistance;
	float cooldown, cooldownLimit;

	state selfState;

	float sp; // speed vector mod
	Vector2f speed;

	map<string, int> inventory;
	void drawInventory(RWindow* render, bool background);
	void drawCooldown(RWindow* render);

	Entity* murderer;
};

