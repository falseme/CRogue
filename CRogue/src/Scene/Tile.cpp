#include "Tile.h"

Tile::Tile(Vector2f pos, Texture* texture, bool hasCollider) {

	sprite.setTexture(*texture);
	sprite.setPosition(pos);
	sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);

	if (hasCollider)
		this->collider = BoxCollider(Vector2f(16, 16), Vector2f(0,0), pos);

}

void Tile::draw(RWindow* render) {
	render->draw(sprite);
	/*// DRAW BOX COLLIDER
	RectangleShape rs(collider.getSize());
	rs.setOrigin(Vector2f(collider.getSize().x / 2, collider.getSize().y / 2));
	rs.setPosition(collider.getPos());
	rs.setFillColor(Color::Red);
	render->draw(rs);
	//*/
}

BoxCollider Tile::getCollider() {
	return collider;
}
