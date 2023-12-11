#include "Player.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "../assets/Assets.h";
#include "../util/Mathv.h"

Player::Player(Vector2f pos, BoxCollider collider, float h, float d, float speed) : Entity(pos, "player", vector<Animation>{Animation(1.2f, Assets::playerIdle, 6), Animation(0.4f, Assets::playerRun, 2), Animation(0.36f, Assets::playerAttack, 3)}, collider, h, d, speed) {

}

void Player::update() {

	speed = Vector2f(0, 0);

	if (Mouse::isButtonPressed(Mouse::Left)) {
		setSelfState(attack);
		// SCALE -1 IF MOUSE IS ON THE LEFT
		if (RWindow::get()->getMousePosition().x < RWindow::get()->getSize().x / 2 + (pos.x - RWindow::get()->getView().getCenter().x)*2)
			sprite.setScale({ -1,1 });
		else
			sprite.setScale({ 1,1 });
	}

	// ATTACK ANIMATION
	if (getSelfState() == attack && !(animations[getSelfState()]).ended()) {
		playStateAnimation();
		return;
	}

	setSelfState(idle); // reset

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
		setSelfState(run);

	Mathv::normalizeAndScale(speed, sp);

	// SCALE -1 IF MOVING TO THE LEFT
	if (speed.x < 0)
		sprite.setScale(Vector2f(-1, 1));
	else if (speed.x > 0)
		sprite.setScale(Vector2f(1, 1));

	// MOVE THE PLAYER, THE CAMERA & PLAY THE ANIMATION
	move(speed);
	RWindow::get()->follow(pos, 25);
	playStateAnimation();

}

void Player::onCollision(BoxCollider other, Vector2f delta) {

	Vector2f d = other.getPos() - collider.getPos();

	if (abs(d.x) > abs(d.y)) {
		move(Vector2f(delta.x, 0));
	}
	else if (abs(d.x) < abs(d.y)) {
		move(Vector2f(0, delta.y));
	}

}
