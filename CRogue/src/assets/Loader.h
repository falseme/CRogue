#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Loader {
public:
	static Texture* loadTexture(string path);
};

