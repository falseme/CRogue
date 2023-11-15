#include "Assets.h"

Texture* Assets::player = NULL;

void Assets::load() {

	player = Loader::loadTexture("data/assets/textures/characters/animations/player/idle/idle0.png");

}
