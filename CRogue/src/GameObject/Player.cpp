#include "Player.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <assets/Assets.h>
#include <util/Mathv.h>
#include <Scene/SceneManager.h>

Player::Player(Vector2f pos, BoxCollider collider, float h, float d, float speed) : Entity(pos, "player", vector<Animation>{Animation(1.2f, Assets::playerIdle, 6), Animation(0.4f, Assets::playerRun, 2), Animation(0.36f, Assets::playerAttack, 3), Animation(0.4f, Assets::playerStunned, 4)}, collider, h, d, speed, 16) {

}

void Player::update() {

	if (selfState == stunned) {
		playStateAnimation();
		move(speed); // speed setted at Entity::attackEntity
		if (animations[currentAnimation].ended())
			selfState = run;
		return;
	}

	speed = Vector2f(0, 0);

	if (Mouse::isButtonPressed(Mouse::Left)) {
		selfState = attack;
		// SCALE -1 IF MOUSE IS ON THE LEFT
		if (RWindow::get()->getMousePosition().x < RWindow::get()->getSize().x / 2 + (pos.x - RWindow::get()->getView().getCenter().x) * 2)
			sprite.setScale({ -1,1 });
		else
			sprite.setScale({ 1,1 });
	}

	// ATTACK ANIMATION & FUNCTION
	if (selfState == attack) {
		if ((animations[selfState]).ended()) {
			list<GameObject*> enemies = SceneManager::getCurrentScene()->findAt("enemy", pos, attackDistance);
			for (GameObject* g : enemies) {
				Entity* en = (Entity*)g;
				if (sprite.getScale().x == -1 && en->getPos().x < pos.x)
					attackEntity(en);
				else if (sprite.getScale().x == 1 && en->getPos().x > pos.x)
					attackEntity(en);
			}
		}
		else {
			playStateAnimation();
			return;
		}
	}

	selfState = idle; // reset

	//MOVEMENT
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

	if (speed.x != 0 || speed.y != 0)
		selfState = run;

	Mathv::normalizeAndScale(speed, sp);

	// SCALE -1 IF MOVING TO THE LEFT
	if (speed.x < 0 && selfState != stunned)
		sprite.setScale(Vector2f(-1, 1));
	else if (speed.x > 0 && selfState != stunned)
		sprite.setScale(Vector2f(1, 1));

	// MOVE THE PLAYER, THE CAMERA & PLAY THE ANIMATION
	move(speed);
	SceneManager::getCurrentScene()->cameraFollow(pos, 20);
	playStateAnimation();

}

