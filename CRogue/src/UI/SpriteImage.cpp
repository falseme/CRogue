#include "SpriteImage.h"

SpriteImage::SpriteImage(Texture* texture, Vector2f pos, Vector2f scale, Vector2f origin) {

	sprite.setTexture(*texture);
	sprite.setPosition(pos);
	sprite.setScale(scale);
	sprite.setOrigin(origin);

}

void SpriteImage::setTexture(Texture* tex) {
	sprite.setTexture(*tex);
}

void SpriteImage::update(Vector2f mousePosition, Vector2f panelPosition) {

}

void SpriteImage::draw(RWindow* render) {
	render->draw(sprite);
}

void SpriteImage::setPosition(Vector2f position) {
	sprite.setPosition(position);
}

Vector2f SpriteImage::getPosition() {
	return sprite.getPosition();
}

void SpriteImage::move(Vector2f delta) {
	sprite.move(delta);
}
