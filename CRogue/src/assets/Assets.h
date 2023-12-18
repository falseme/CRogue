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
	static vector<Texture*> playerHeal;
	static Texture* playerDead;

	static vector<Texture*> skelyIdle;
	static vector<Texture*> skelyRun;
	static vector<Texture*> skelyAttack;
	static vector<Texture*> skelyStunned;
	static vector<Texture*> skelyHeal;
	static Texture* skelyDead;

	static vector<Texture*> skelyIdleSW;
	static vector<Texture*> skelyRunSW;
	static vector<Texture*> skelyAttackSW;
	static vector<Texture*> skelyStunnedSW;
	static vector<Texture*> skelyHealSW;
	static Texture* skelyDeadSW;

	static vector<Texture*> skelyIdle_pow;
	static vector<Texture*> skelyRun_pow;
	static vector<Texture*> skelyAttack_pow;
	static vector<Texture*> skelyStunned_pow;
	static vector<Texture*> skelyHeal_pow;
	static Texture* skelyDead_pow;

	static vector<Texture*> skelyIdleSW_pow;
	static vector<Texture*> skelyRunSW_pow;
	static vector<Texture*> skelyAttackSW_pow;
	static vector<Texture*> skelyStunnedSW_pow;
	static vector<Texture*> skelyHealSW_pow;
	static Texture* skelyDeadSW_pow;

	static map<string, vector<Texture*>> tilemap;

	static Texture* doorClosed;
	static vector<Texture*> doorOpen;
	static Texture* ladder;

	static Texture* key;
	static Texture* healthPotion;
	static Texture* healthPotion_small;

	static Image mouse;

	static void load();
};

