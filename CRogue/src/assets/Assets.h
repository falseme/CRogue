#pragma once

#include <SFML/Graphics.hpp>
#include "Loader.h"

using namespace sf;

class Assets {
public:
	static Texture** playerIdle;
	static Texture** playerRun;
	static Texture** playerAttack;
	static Texture** playerStunned;
	static Texture** skelyIdle;
	static Texture** skelyRun;
	static Texture** skelyAttack;
	static Texture** skelyStunned;

	static map<string, vector<Texture*>> tilemap;

	static Image mouse;

	static void load();
};

