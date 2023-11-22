#pragma once
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics.hpp>
#include "../UI/RWindow.h"

using namespace sf;


class Tile
{
public:
	Tile(unsigned int x, unsigned int y, const Image& imagen);
	void render(RWindow* render);
private:
	Sprite sprite;
};

