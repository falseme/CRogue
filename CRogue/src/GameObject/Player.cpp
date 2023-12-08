#include "Player.h"

#include <SFML/Window/Keyboard.hpp>

Player::Player(Vector2f pos, Animation anim, BoxCollider collider, float h, float d) : Entity(pos, anim, collider, h, d) {

}

void Player::update() {

	animation.play();
	sprite.setTexture(*animation.getFrame());

	speed = Vector2f(0, 0);

	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		speed += Vector2f(0, -1);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		speed += Vector2f(0, 1);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		speed += Vector2f(-1, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		speed += Vector2f(1, 0);
	}

	if (speed.x < 0)
		sprite.setScale(Vector2f(-1, 1));
	else if (speed.x > 0)
		sprite.setScale(Vector2f(1, 1));

	move(speed);

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
