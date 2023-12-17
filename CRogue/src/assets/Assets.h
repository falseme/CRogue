#pragma once

#include <SFML/Graphics.hpp>
#include "Loader.h"

using namespace sf;

class Assets {
public:
	static vector<Texture*> playerIdle;
	static vector<Texture*> playerRun;
	static vector<Texture*> playerAttack;
	static vector<Texture*> playerStunned;

	static vector<Texture*> skelyIdle;
	static vector<Texture*> skelyRun;
	static vector<Texture*> skelyAttack;
	static vector<Texture*> skelyStunned;
	static Texture* skelyDead;

	static vector<Texture*> skelyIdleSW;
	static vector<Texture*> skelyRunSW;
	static vector<Texture*> skelyAttackSW;
	static vector<Texture*> skelyStunnedSW;
	static Texture* skelyDeadSW;

	static map<string, vector<Texture*>> tilemap;

	static Image mouse;

	static void load();
};

