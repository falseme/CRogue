#include "Tile.h"

Tile::Tile(Vector2f pos, Vector2f offsetTex, const Image& image, bool hasCollider) {

	Texture* texture = new Texture();
	texture->loadFromImage(image, IntRect(offsetTex.x * 16, offsetTex.y * 16, 16, 16));
	sprite.setTexture(*texture);
	sprite.setPosition(pos.x * 16, pos.y * 16);

	if (hasCollider) {
		this->collider = BoxCollider(Vector2f(pos.x * 16, pos.y * 16), Vector2f(16, 16));
	}

}

void Tile::draw(RWindow* render) {
	render->draw(sprite);
}

BoxCollider Tile::getCollider() {
	return collider;
}
