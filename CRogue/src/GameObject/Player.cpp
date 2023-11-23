#include "Player.h"

Player::Player(Vector2f pos, Animation anim, float h, float d) : Entity(pos, anim, h, d) {

}

void Player::update() {

	animation.play();
	sprite.setTexture(*animation.getFrame());

	move(Vector2f(0.1f, 0.f));
	sprite.setPosition(pos);

}
