#pragma once
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics.hpp>
#include "../UI/RWindow.h"
#include "../collision/CollisionBox.h"

using namespace sf;


class Tile
{
public:
	Tile(Vector2f pos, Vector2f offsetTex, const Image& image, bool collider);
	void draw(RWindow* render);
private:
	Sprite sprite;
	CollisionBox collider;
};

