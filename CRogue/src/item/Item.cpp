#include "Item.h"

Item::Item(Texture* tex, string name) {
	sprite.setTexture(*tex);
	sprite.setScale(0.5f, 0.5f);
	this->name = name;
}

string Item::getName() {
	return name;
}

const Texture* Item::getTexture() {
	return sprite.getTexture();
}

Sprite& Item::getSprite() {
	return sprite;
}
