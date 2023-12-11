#include "Enemy.h"

#include "../util/Mathv.h"

Enemy::Enemy(Vector2f pos, vector<Animation> anim, BoxCollider collider, float h, float d, float speed) : Entity(pos, "enemy", anim, collider, h, d, speed) {

}

void Enemy::update() {

	GameObject* pl = GameObject::find("player");

	speed = Vector2f(0, 0);

	int followDistance = 100;
	int attackDistance = 18;

	switch (getSelfState()) {
	case idle:

		if (pl == NULL)
			break;

		if (Mathv::distance(pos, pl->getPos()) < followDistance) {
			setSelfState(run);
		}

		break;
	case run:

		if (Mathv::distance(pos, pl->getPos()) < attackDistance) {
			setSelfState(attack);
			Vector2f d = pl->getPos() - pos;
			if (d.x == 0)
				break;
			sprite.setScale(Vector2f(d.x/abs(d.x), 1));
			break;
		}
		else if (Mathv::distance(pos, pl->getPos()) >= followDistance) {
			setSelfState(idle);
			break;
		}

		moveTo(pl->getPos());

		break;
	case attack:

		if (animations[currentAnimation].ended())
			setSelfState(run);

		break;
	}

	if (speed.x < 0)
		sprite.setScale(Vector2f(-1, 1));
	else if (speed.x > 0)
		sprite.setScale(Vector2f(1, 1));

	playStateAnimation();

}

void Enemy::onCollision(BoxCollider other, Vector2f delta) {

	Vector2f d = other.getPos() - collider.getPos();

	if (abs(d.x) > abs(d.y)) {
		move(Vector2f(delta.x, 0));
	}
	else if (abs(d.x) < abs(d.y)) {
		move(Vector2f(0, delta.y));
	}

}
