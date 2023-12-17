#pragma once
#include "GameObject.h"
class Entity :public GameObject {
public:
	static const enum state { idle, run, attack, stunned, dead };

	Entity(Vector2f pos, string name, vector<Animation> anim, BoxCollider collider, float h, float d, float speed, int attackDistance);

	void update() override;

	float GetHealth();
	void SetHealth(float h);
	float GetDamage();
	void SetDamage(float d);

	void attackEntity(Entity* en);
	void moveTo(Vector2f target);
	void onCollision(BoxCollider other, Vector2f delta) override;

	void playStateAnimation();
	state getSelfState() const;

protected:
	float health;
	float damage;
	int attackDistance;

	state selfState;

	float sp; // speed vector mod
	Vector2f speed;
};

