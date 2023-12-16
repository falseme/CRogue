#include "Assets.h"

Texture** Assets::playerIdle = NULL;
Texture** Assets::playerRun = NULL;
Texture** Assets::playerAttack = NULL;
Texture** Assets::playerStunned = NULL;
Texture** Assets::skelyIdle = NULL;
Texture** Assets::skelyRun = NULL;
Texture** Assets::skelyAttack = NULL;
Texture** Assets::skelyStunned = NULL;
Texture* Assets::skelyDead = NULL;

map<string, vector<Texture*>> Assets::tilemap;

Image Assets::mouse;

void Assets::load() {

	playerIdle = new Texture * [6] {
		Loader::loadTexture("data/assets/textures/animations/player/player_idle0.png"),
		Loader::loadTexture("data/assets/textures/animations/player/player_idle1.png"),
		Loader::loadTexture("data/assets/textures/animations/player/player_idle2.png"),
		Loader::loadTexture("data/assets/textures/animations/player/player_idle2.png"),
		Loader::loadTexture("data/assets/textures/animations/player/player_idle1.png"),
		Loader::loadTexture("data/assets/textures/animations/player/player_idle0.png")
	};

	playerRun = new Texture * [2] {
		Loader::loadTexture("data/assets/textures/animations/player/player_run0.png"),
		Loader::loadTexture("data/assets/textures/animations/player/player_run1.png")
	};

	playerAttack = new Texture * [3] {
		Loader::loadTexture("data/assets/textures/animations/player/player_attack0.png"),
		Loader::loadTexture("data/assets/textures/animations/player/player_attack1.png"),
		Loader::loadTexture("data/assets/textures/animations/player/player_attack2.png")
	};

	playerStunned = new Texture * [4] {
		Loader::loadTexture("data/assets/textures/animations/player/player_stunned0.png"),
		Loader::loadTexture("data/assets/textures/animations/player/player_stunned1.png"),
		Loader::loadTexture("data/assets/textures/animations/player/player_stunned0.png"),
		Loader::loadTexture("data/assets/textures/animations/player/player_stunned1.png")
	};

	skelyIdle = new Texture * [6] {
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle0.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle1.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle2.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle2.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle1.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle0.png")
	};

	skelyRun = new Texture * [2] {
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_run0.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_run1.png")
	};

	skelyAttack = new Texture * [5] {
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_attack0.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_attack0.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_attack0.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_attack1.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_attack2.png")
	};

	skelyStunned = new Texture * [4] {
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_stunned0.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_stunned1.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_stunned0.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_stunned1.png")
	};

	skelyDead = Loader::loadTexture("data/assets/textures/animations/skeleton/skely_dead.png");

	//TILEMAP
	Image tileset = Loader::loadTexture("data/assets/textures/tileset/dungeon_tileset_v.png")->copyToImage();

	vector<string> keys{ "O0","O0","O0","O1","O2","O3","O4","O5","O6","O7","O8","#0","#1","#2","#3","#4","#5","#6","#7" };

	for (int j = 0; j < tileset.getSize().y - 16; j += 16) {
		for (int i = 0; i < tileset.getSize().x; i += 16) {

			Texture* tex = new Texture();
			tex->loadFromImage(tileset, IntRect(i, j, 16, 16));
			tilemap[keys[j / 16]].push_back(tex);

		}
	}

	//GUI
	mouse = Loader::loadTexture("data/assets/textures/gui/mouse.png")->copyToImage();

}
