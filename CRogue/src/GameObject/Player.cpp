#include "Player.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../assets/Assets.h";

Player::Player(Vector2f pos, BoxCollider collider, float h, float d) : Entity(pos, "player", vector<Animation>{Animation(1.2f, Assets::playerIdle, 6), Animation(0.4f, Assets::playerRun, 2), Animation(0.36f, Assets::playerAttack, 3)}, collider, h, d) {

}

void Player::update() {

	float sp = 1.5f;
	speed = Vector2f(0, 0);

	if (Mouse::isButtonPressed(Mouse::Left)) {
		setSelfState(attack);
	}

	if (getSelfState() == attack && !(animations[getSelfState()]).ended()) {
		playStateAnimation();
		return;
	}

	setSelfState(idle);

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

	if (speed.x != 0 && speed.y != 0) {
		float mod = sqrt(speed.x * speed.x + speed.y * speed.y);
		speed.x /= mod;
		speed.y /= mod;
		speed.x *= sp;
		speed.y *= sp;
	}

	if (speed.x < 0)
		sprite.setScale(Vector2f(-1, 1));
	else if (speed.x > 0)
		sprite.setScale(Vector2f(1, 1));

	move(speed);
	playStateAnimation();

}

void Player::onCollision(BoxCollider other, Vector2f delta) {

	Vector2f d = other.getPos() - pos;

	if (abs(d.x) > abs(d.y)) {
		move(Vector2f(delta.x, 0));
	}
	else if (abs(d.x) < abs(d.y)) {
		move(Vector2f(0, delta.y));
	}

}
