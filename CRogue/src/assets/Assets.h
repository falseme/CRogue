#pragma once

#include <SFML/Graphics.hpp>
#include "Loader.h"

using namespace sf;

class Assets {
public:
	static Texture** playerIdle_anim;
	static void load();
};

