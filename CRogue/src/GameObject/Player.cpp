#include "Player.h"

#include <SFML/Window/Keyboard.hpp>

Player::Player(Vector2f pos, Animation anim, CollisionBox collider, float h, float d) : Entity(pos, anim, collider, h, d) {

}

void Player::update() {

	animation.play();
	sprite.setTexture(*animation.getFrame());

	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		move(Vector2f(0, -1));
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		move(Vector2f(0, 1));
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		move(Vector2f(-1, 0));
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		move(Vector2f(1, 0));
	}

}
