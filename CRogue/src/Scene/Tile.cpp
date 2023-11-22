#include "Tile.h"
Tile::Tile(unsigned int x, unsigned int y, const Image& imagen) {
	Texture* texture = new Texture();
	texture->loadFromImage(imagen, IntRect(x * 16, y * 16, 16, 16));
	sprite.setTexture(*texture);
	sprite.setScale(Vector2f(2, 2));
	sprite.setPosition(x * 16*2, y * 16*2);
}

void Tile::render(RWindow* render) {
	render->draw(sprite);
}