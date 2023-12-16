#define _USE_MATH_DEFINES
#include "Enemy.h"

#include <util/Mathv.h>
#include <Scene/SceneManager.h>

Enemy::Enemy(Vector2f pos, vector<Animation> anim, BoxCollider collider, float h, float d, float speed, int attackDistance, int followDistance) : Entity(pos, "enemy", anim, collider, h, d, speed, attackDistance) {
	this->followDistance = followDistance;
}

void Enemy::update() {

	GameObject* pl = SceneManager::getCurrentScene()->find("player");

	switch (selfState) {
	case idle:

		speed = Vector2f(0, 0);

		if (animations[currentAnimation].ended() || pl == nullptr) {
			int nDeg = (rand() % 45) * (rand() % 8);
			float x = cos(nDeg * M_PI / 180);
			float y = sin(nDeg * M_PI / 180);
			speed = Vector2f(x, y);
			Mathv::normalizeAndScale(speed, sp/3);
			selfState = run;
			break;
		}

		if (Mathv::distance(pos, pl->getPos()) < followDistance) {
			selfState = run;
		}

		break;
	case run:

		if (pl == nullptr || Mathv::distance(pos, pl->getPos()) >= followDistance) {
			move(speed);
			if (animations[currentAnimation].ended())
				selfState = idle;
			break;
		}

		if (Mathv::distance(pos, pl->getPos()) < attackDistance) {
			selfState = attack;
			Vector2f d = pl->getPos() - pos;
			if (d.x == 0)
				break;
			sprite.setScale(Vector2f(d.x / abs(d.x), 1));
			break;
		}
		else if (Mathv::distance(pos, pl->getPos()) >= followDistance) {
			selfState = idle;
			break;
		}

		moveTo(pl->getPos());

		break;
	case attack:

		if (animations[currentAnimation].ended()) {
			float delta = pl->getPos().x - pos.x;
			if (delta < 0 && sprite.getScale().x < 0 || delta >=0 && sprite.getScale().x > 0)
				attackEntity((Entity*)pl);
			selfState = run;
		}

		break;
	case stunned:

		move(speed);
		if (animations[currentAnimation].ended())
			selfState = run;

		break;
	}

	if (speed.x < 0 && selfState != stunned)
		sprite.setScale(Vector2f(-1, 1));
	else if (speed.x > 0 && selfState != stunned)
		sprite.setScale(Vector2f(1, 1));

	playStateAnimation();

}

