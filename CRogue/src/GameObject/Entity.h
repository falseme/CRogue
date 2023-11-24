#pragma once
#include "GameObject.h"
class Entity :public GameObject {
private:
	float health;
	float damage;
public:
	void update() override;
	Entity(Vector2f pos, Animation anim, CollisionBox collider, float h, float d);
	float GetHealth();
	void SetHealth(float h);
	float GetDamage();
	void SetDamage(float d);
	void Attacked(float d);

};

