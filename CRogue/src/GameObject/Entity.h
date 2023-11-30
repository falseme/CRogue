#pragma once
#include "GameObject.h"
class Entity :public GameObject {
private:
	float health;
	float damage;
protected:
	Vector2f speed;
public:
	void update() override;
	Entity(Vector2f pos, Animation anim, BoxCollider collider, float h, float d);
	float GetHealth();
	void SetHealth(float h);
	float GetDamage();
	void SetDamage(float d);
	void Attacked(float d);
	void onCollision(BoxCollider other) override;
};

