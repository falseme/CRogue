#include "Assets.h"

Texture** Assets::playerIdle_anim = NULL;
Texture* Assets::Tileset = NULL;
void Assets::load() {

	playerIdle_anim = new Texture*[4] {
		Loader::loadTexture("data/assets/textures/characters/animations/player/idle/idle0.png"),
		Loader::loadTexture("data/assets/textures/characters/animations/player/idle/idle1.png"),
		Loader::loadTexture("data/assets/textures/characters/animations/player/idle/idle2.png"),
		Loader::loadTexture("data/assets/textures/characters/animations/player/idle/idle3.png")
	};

	Tileset = Loader::loadTexture("data/assets/textures/tileset/dungeon_tileset.png");


}
