#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Item {
public:
	Item(Texture* tex, string name);

	string getName();
	const Texture* getTexture();
	Sprite& getSprite();
private:
	Sprite sprite;
	string name;
};

