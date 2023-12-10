#include "Assets.h"

Texture** Assets::playerIdle = NULL;
Texture** Assets::playerRun = NULL;
Texture** Assets::playerAttack = NULL;
Texture** Assets::skelyIdle = NULL;
Texture* Assets::Tileset = NULL;

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

	skelyIdle = new Texture * [6] {
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle0.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle1.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle2.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle2.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle1.png"),
		Loader::loadTexture("data/assets/textures/animations/skeleton/skely_idle0.png")
	};

	Tileset = Loader::loadTexture("data/assets/textures/tileset/dungeon_tileset.png");

}
