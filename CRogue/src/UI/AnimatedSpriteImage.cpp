#include "AnimatedSpriteImage.h"

AnimatedSpriteImage::AnimatedSpriteImage(Animation anim, Vector2f pos, Vector2f scale, Vector2f origin) {
	animation = anim;
	sprite.setPosition(pos);
	sprite.setScale(scale);
	sprite.setOrigin(origin);
}

void AnimatedSpriteImage::update(Vector2f mousePosition, Vector2f panelPosition) {
	animation.play();
	sprite.setTexture(*animation.getFrame());
}

void AnimatedSpriteImage::draw(RWindow* render) {
	render->draw(sprite);
}

void AnimatedSpriteImage::setPosition(Vector2f position) {
	sprite.setPosition(position);
}

Vector2f AnimatedSpriteImage::getPosition() {
	return sprite.getPosition();
}

void AnimatedSpriteImage::move(Vector2f delta) {
	sprite.move(delta);
}
