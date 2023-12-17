#include "Player.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <assets/Assets.h>
#include <util/Mathv.h>
#include <scene/SceneManager.h>

Player::Player(Vector2f pos, BoxCollider collider, float h, float d, float speed) : Entity(pos, "player", vector<Animation>{Animation(1.2f, Assets::playerIdle), Animation(0.6f, Assets::playerRun), Animation(0.36f, Assets::playerAttack), Animation(0.4f, Assets::playerStunned), Animation(Assets::playerDead)}, collider, h, d, speed, 16) {

}

void Player::update() {

	switch (selfState) {
	case idle:

		if (moving())
			selfState = run;
		if (attacking())
			selfState = attack;

		break;
	case run:

		if (!moving())
			selfState = idle;
		if (attacking())
			selfState = attack;

		break;
	case attack:

		speed = Vector2f(0, 0);

		if ((animations[selfState]).ended()) {
			list<GameObject*> enemies = SceneManager::getCurrentScene()->findAt("enemy", pos, attackDistance);
			for (GameObject* g : enemies) {
				Entity* en = (Entity*)g;
				if (sprite.getScale().x == -1 && en->getPos().x < pos.x)
					attackEntity(en);
				else if (sprite.getScale().x == 1 && en->getPos().x > pos.x)
					attackEntity(en);
			}
			selfState = idle;
		}

		break;
	case stunned:

		if (animations[currentAnimation].ended())
			selfState = run;

		break;
	}

	move(speed);
	SceneManager::getCurrentScene()->cameraFollow(pos, 20);
	playStateAnimation();

}

bool Player::moving() {

	speed = { 0,0 };

	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		speed += Vector2f(0, -sp);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		speed += Vector2f(0, sp);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		speed += Vector2f(-sp, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		speed += Vector2f(sp, 0);
	}

	Mathv::normalizeAndScale(speed, sp);

	if (speed.x < 0)
		sprite.setScale(Vector2f(-1, 1));
	else if (speed.x > 0)
		sprite.setScale(Vector2f(1, 1));

	if (speed.x != 0 || speed.y != 0)
		return true;
	return false;

}

bool Player::attacking() {

	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (RWindow::get()->getMousePosition().x < RWindow::get()->getSize().x / 2 + (pos.x - RWindow::get()->getView().getCenter().x) * 3)
			sprite.setScale({ -1,1 });
		else
			sprite.setScale({ 1,1 });

		return true;
	}

	return false;

}

