#include "Tile.h"

Tile::Tile(Vector2f pos, Vector2f offsetTex, const Image& image) {
	Texture* texture = new Texture();
	texture->loadFromImage(image, IntRect(offsetTex.x * 16, offsetTex.y * 16, 16, 16));
	sprite.setTexture(*texture);
	sprite.setPosition(pos.x * 16, pos.y * 16);
}

void Tile::draw(RWindow* render) {
	render->draw(sprite);
}