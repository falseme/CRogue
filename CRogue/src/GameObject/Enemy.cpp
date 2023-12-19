#define _USE_MATH_DEFINES
#include "Enemy.h"

#include <scene/SceneManager.h>
#include <util/Mathv.h>
#include <util/Timef.h>

Enemy::Enemy(Vector2f pos, vector<Animation> anim, float h, float d, float speed, int attackDistance, int followDistance, float cooldownLimit) : Entity(pos, "enemy", anim, BoxCollider(Vector2f(12, 12), Vector2f(0, 2)), h, h, d, speed, attackDistance, cooldownLimit) {
	this->followDistance = followDistance;
}

void Enemy::update() {

	playStateAnimation();

	Entity* pl = (Entity*)SceneManager::getCurrentScene()->find("player");

	switch (selfState) {
	case idle:

		speed = Vector2f(0, 0);

		if (animations[currentAnimation].ended() || pl == nullptr) {
			int nDeg = 45 * (rand() % 8);
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

		if (Mathv::distance(pos, pl->getPos()) < attackDistance && cooldown >= cooldownLimit) {
			selfState = attack;
			cooldown = 0;
			float delta = pl->getPos().x - pos.x;
			if (delta == 0) // prevent "0/0"
				break;
			sprite.setScale(Vector2f(delta / abs(delta), 1));
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
		if (animations[currentAnimation].ended()) {
			int n = rand() % 100;
			if (n < 5 && useHealthPotion())
				selfState = heal;
			else
				selfState = idle;

			if (health <= 0) {
				selfState = dead;
				collider = BoxCollider();
				speed = { 0,0 };
				giveItems(murderer);
				murderer->addKill();
			}
		}

		break;
	case heal:

		if (animations[currentAnimation].ended())
			selfState = idle;

		break;
	}

	if (cooldown < cooldownLimit)
		cooldown += Timef::deltaTime();

	if (speed.x < 0 && selfState != stunned)
		sprite.setScale(Vector2f(-1, 1));
	else if (speed.x > 0 && selfState != stunned)
		sprite.setScale(Vector2f(1, 1));

}

void Enemy::draw(RWindow* render) {
	render->draw(sprite);
	drawInventory(render, false);
	drawCooldown(render);
}

