#pragma once
#include "GameObject.h"
class Entity :public GameObject {
public:
	static const enum state { idle, run, attack };

	Entity(Vector2f pos, std::string name, vector<Animation> anim, BoxCollider collider, float h, float d);

	void update() override;

	float GetHealth();
	void SetHealth(float h);
	float GetDamage();
	void SetDamage(float d);

	void Attacked(float d);
	void onCollision(BoxCollider other, Vector2f delta) override;

	void playStateAnimation();

	state getSelfState();
	void setSelfState(state s);
private:
	float health;
	float damage;
	state selfState;
protected:
	Vector2f speed;
};

