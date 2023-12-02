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

	move(speed);

}

void Player::onCollision(BoxCollider other) {

	Vector2f delta = other.getPos() - collider.getPos();

	if (abs(delta.x) > abs(delta.y)) {
		move(Vector2f(-speed.x, 0));
	}
	else if (abs(delta.x) < abs(delta.y)) {
		move(Vector2f(0, -speed.y));
	}

}
