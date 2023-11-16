#include "Assets.h"

Texture* Assets::player_idle0 = NULL;
Texture* Assets::player_idle1 = NULL;
Texture* Assets::player_idle2 = NULL;
Texture* Assets::player_idle3 = NULL;

void Assets::load() {

	player_idle0 = Loader::loadTexture("data/assets/textures/characters/animations/player/idle/idle0.png");
	player_idle1 = Loader::loadTexture("data/assets/textures/characters/animations/player/idle/idle1.png");
	player_idle2 = Loader::loadTexture("data/assets/textures/characters/animations/player/idle/idle2.png");
	player_idle3 = Loader::loadTexture("data/assets/textures/characters/animations/player/idle/idle3.png");

}
