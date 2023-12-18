#include "Player.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <assets/Assets.h>
#include <scene/SceneManager.h>
#include <util/Mathv.h>
#include <util/Timef.h>
#include <item/HealthPotion.h>

Player::Player(Vector2f pos, float h, float d, float speed) : Entity(pos, "player", { Animation(1.2f, Assets::playerIdle), Animation(0.6f, Assets::playerRun), Animation(0.36f, Assets::playerAttack), Animation(0.4f, Assets::playerStunned), Animation(0.4f, Assets::playerHeal), Animation(Assets::playerDead) }, BoxCollider(Vector2f(12, 12), Vector2f(0, 2)), h, d, speed, 16) {
	showInventory = false;
}

void Player::update() {

	playStateAnimation();

	switch (selfState) {
	case idle:

		if (moving())
			selfState = run;
		if (attacking())
			selfState = attack;
		if (healing())
			selfState = heal;

		break;
	case run:

		if (!moving())
			selfState = idle;
		if (attacking())
			selfState = attack;
		if (healing())
			selfState = heal;

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

		if (animations[currentAnimation].ended()) {
			selfState = run;
		}

		break;
	case heal:

		speed = { 0,0 };

		if (animations[currentAnimation].ended()) {

			HealthPotion* p = (HealthPotion*)getItem("health_potion");
			if (p) {
				health += p->getHealing();
				inventory.remove(p);
			}
			delete p;

			selfState = idle;
		}

		break;
	}

	move(speed);
	SceneManager::getCurrentScene()->cameraFollow(pos, 20);

	if (Keyboard::isKeyPressed(Keyboard::Tab))
		showInventory = true;
	else
		showInventory = false;

}

void Player::draw(RWindow* render) {

	render->draw(sprite);
	if (showInventory)
		drawInventory(render, true);

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

	Mathv::normalizeAndScale(speed, sp * Timef::deltaTimeFactor());

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

bool Player::healing() {

	if (Keyboard::isKeyPressed(Keyboard::H) && getItem("health_potion"))
		return true;
	return false;

}

