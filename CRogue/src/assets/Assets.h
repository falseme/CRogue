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

	static Texture* ladder;
	static Texture* doorClosed;
	static vector<Texture*> doorOpen;
	static vector<Texture*> flag;
	static vector<Texture*> torch;
	static vector<Texture*> torch_side;

	static Texture* key;
	static Texture* healthPotion;
	static Texture* healthPotion_small;

	static vector<Texture*> WASD;
	static vector<Texture*> H;
	static vector<Texture*> ESC;
	static vector<Texture*> TAB;
	static Texture* mouse;

	static Font defaultFont;
	static Font titleFont;

	static Texture* heart;
	static Texture* heart_half;
	static Texture* heart_empty;

	static void load();
};

