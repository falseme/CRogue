#pragma once

#include <SFML/Graphics.hpp>
#include "Loader.h"

using namespace sf;

class Assets {
public:
	static Texture** playerIdle_anim;
	static Texture* Tileset;//puntero que apunta a donde esta guardada la imagen del fondo

	static void load();
};

