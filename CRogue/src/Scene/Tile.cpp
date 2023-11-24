#include "Tile.h"

Tile::Tile(Vector2f pos, Vector2f offsetTex, const Image& image, bool collider) {
	Texture* texture = new Texture();
	texture->loadFromImage(image, IntRect(offsetTex.x * 16, offsetTex.y * 16, 16, 16));
	sprite.setTexture(*texture);
	sprite.setPosition(pos.x * 16, pos.y * 16);
	if (collider) {
		this->collider = CollisionBox(Vector2f(pos.x + 8, pos.y + 8), Vector2f(16, 16));
		sprite.setColor(Color(255, 0, 0, 255));//TEST - BORRAR
	}
}

void Tile::draw(RWindow* render) {
	render->draw(sprite);
}