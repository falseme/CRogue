#include "Assets.h"

vector<Texture*> Assets::playerIdle;
vector<Texture*> Assets::playerRun;
vector<Texture*> Assets::playerAttack;
vector<Texture*> Assets::playerStunned;
vector<Texture*> Assets::skelyIdle;
vector<Texture*> Assets::skelyRun;
vector<Texture*> Assets::skelyAttack;
vector<Texture*> Assets::skelyStunned;
Texture* Assets::skelyDead = nullptr;
vector<Texture*> Assets::skelyIdleSW;
vector<Texture*> Assets::skelyRunSW;
vector<Texture*> Assets::skelyAttackSW;
vector<Texture*> Assets::skelyStunnedSW;
Texture* Assets::skelyDeadSW = nullptr;

map<string, vector<Texture*>> Assets::tilemap;

Image Assets::mouse;

void Assets::load() {

	playerIdle = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_idle.png", 24);
	playerRun = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_run.png", 24);
	playerAttack = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_attack.png", 24);
	playerStunned = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_stunned.png", 24);

	skelyIdle = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_idle.png", 24);
	skelyRun = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_run.png", 24);
	skelyAttack = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_attack.png", 24);
	skelyStunned = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_stunned.png", 24);
	skelyDead = Loader::loadTexture("data/assets/textures/animations/skeleton/skely_dead.png");

	skelyIdleSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_idle.png", 24);
	skelyRunSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_run.png", 24);
	skelyAttackSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_attack.png", 24);
	skelyStunnedSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_stunned.png", 24);
	skelyDeadSW = Loader::loadTexture("data/assets/textures/animations/skeleton_sword/skely_dead.png");

	//TILEMAP
	vector<string> keys{ "O0","O0","O0","O1","O2","O3","O4","O5","O6","O7","O8","#0","#1","#2","#3","#4","#5","#6","#7" };
	Loader::loadTileMap(tilemap, keys, "data/assets/textures/tileset/dungeon_tileset_v.png", 16);

	//GUI
	mouse = Loader::loadTexture("data/assets/textures/gui/mouse.png")->copyToImage();

}
