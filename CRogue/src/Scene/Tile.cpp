#include "Tile.h"
Tile::Tile(unsigned int x, unsigned int y, const Image& imagen) {
	Texture texture;
	texture.loadFromImage(imagen, IntRect(x * 32, y * 32, 32, 32));
	sprite.setTexture(texture);

}

void Tile::render(RWindow* render) {
	render->draw(sprite);
}