#pragma once
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics.hpp>
#include "../UI/RWindow.h"
#include "../collision/BoxCollider.h"

using namespace sf;

class Tile {
public:
	Tile(Vector2f pos, Texture* texture, bool hasCollider);
	void draw(RWindow* render);
	BoxCollider getCollider();
private:
	Sprite sprite;
	BoxCollider collider;
};

