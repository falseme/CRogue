#include "Enemy.h"

Enemy::Enemy(Vector2f pos, vector<Animation> anim, BoxCollider collider, float h, float d) : Entity(pos, anim, collider, h, d) {

}

void Enemy::update() {

};

void Enemy::onCollision(BoxCollider other, Vector2f delta) {

	Vector2f d = other.getPos() - pos;

	if (abs(d.x) > abs(d.y)) {
		move(Vector2f(delta.x, 0));
	}
	else if (abs(d.x) < abs(d.y)) {
		move(Vector2f(0, delta.y));
	}

}
