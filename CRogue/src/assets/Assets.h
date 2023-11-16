#pragma once

#include <SFML/Graphics.hpp>
#include "Loader.h"

using namespace sf;

class Assets {
public:
	static Texture* player_idle0, * player_idle1, * player_idle2, * player_idle3;
	static void load();
};

