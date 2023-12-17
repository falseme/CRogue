#define _USE_MATH_DEFINES
#include "Enemy.h"

#include <util/Mathv.h>
#include <util/Timef.h>
#include <scene/SceneManager.h>

Enemy::Enemy(Vector2f pos, vector<Animation> anim, float h, float d, float speed, int attackDistance, int followDistance) : Entity(pos, "enemy", anim, BoxCollider(Vector2f(12, 12), Vector2f(0, 2)), h, d, speed, attackDistance) {
	this->followDistance = followDistance;
}

void Enemy::update() {

	Entity* pl = (Entity*)SceneManager::getCurrentScene()->find("player");

	switch (selfState) {
	case idle:

		speed = Vector2f(0, 0);

		if (animations[currentAnimation].ended() || pl == nullptr) {
			int nDeg = (rand() % 45) * (rand() % 8);
			float x = cos(nDeg * M_PI / 180);
			float y = sin(nDeg * M_PI / 180);
			speed = Vector2f(x, y);
			Mathv::normalizeAndScale(speed, sp / 3 * Timef::deltaTimeFactor());
			selfState = run;
			break;
		}

		if (Mathv::distance(pos, pl->getPos()) < followDistance && pl->getSelfState() != dead) {
			selfState = run;
		}

		break;
	case run:

		if (pl == nullptr || Mathv::distance(pos, pl->getPos()) >= followDistance || pl->getSelfState() == dead) {
			move(speed);
			if (animations[currentAnimation].ended())
				selfState = idle;
			break;
		}

		if (Mathv::distance(pos, pl->getPos()) < attackDistance) {
			selfState = attack;
			float delta = pl->getPos().x - pos.x;
			if (delta == 0) // prevent "0/0"
				break;
			sprite.setScale(Vector2f(delta / abs(delta), 1));
			break;
		}

		moveTo(pl->getPos());

		break;
	case attack:

		if (animations[currentAnimation].ended()) {
			float delta = pl->getPos().x - pos.x;
			if (delta < 0 && sprite.getScale().x < 0 || delta >= 0 && sprite.getScale().x > 0)
				attackEntity((Entity*)pl);
			selfState = idle;
		}

		break;
	case stunned:

		move(speed);
		if (animations[currentAnimation].ended())
			selfState = idle;

		break;
	}

	if (speed.x < 0 && selfState != stunned)
		sprite.setScale(Vector2f(-1, 1));
	else if (speed.x > 0 && selfState != stunned)
		sprite.setScale(Vector2f(1, 1));

	playStateAnimation();

}

void Enemy::draw(RWindow* render) {
	render->draw(sprite);
	drawInventory(render);
}

