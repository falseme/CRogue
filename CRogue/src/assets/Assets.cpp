#include "Assets.h"

vector<Texture*> Assets::playerIdle;
vector<Texture*> Assets::playerRun;
vector<Texture*> Assets::playerAttack;
vector<Texture*> Assets::playerStunned;
Texture* Assets::playerDead = nullptr;

vector<Texture*> Assets::skelyIdle;
vector<Texture*> Assets::skelyRun;
vector<Texture*> Assets::skelyAttack;
vector<Texture*> Assets::skelyStunned;
Texture* Assets::skelyDead = nullptr;

vector<Texture*> Assets::skelyIdle_pow;
vector<Texture*> Assets::skelyRun_pow;
vector<Texture*> Assets::skelyAttack_pow;
vector<Texture*> Assets::skelyStunned_pow;
Texture* Assets::skelyDead_pow = nullptr;

vector<Texture*> Assets::skelyIdleSW;
vector<Texture*> Assets::skelyRunSW;
vector<Texture*> Assets::skelyAttackSW;
vector<Texture*> Assets::skelyStunnedSW;
Texture* Assets::skelyDeadSW = nullptr;

vector<Texture*> Assets::skelyIdleSW_pow;
vector<Texture*> Assets::skelyRunSW_pow;
vector<Texture*> Assets::skelyAttackSW_pow;
vector<Texture*> Assets::skelyStunnedSW_pow;
Texture* Assets::skelyDeadSW_pow = nullptr;

map<string, vector<Texture*>> Assets::tilemap;

Texture* Assets::doorClosed = nullptr;
vector<Texture*> Assets::doorOpen;

Texture* Assets::key;

Image Assets::mouse;

void Assets::load() {

	//ENTITIES

	playerIdle = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_idle.png", 24, 24);
	playerRun = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_run.png", 24, 24);
	playerAttack = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_attack.png", 24, 24);
	playerStunned = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_stunned.png", 24, 24);
	playerDead = Loader::loadTexture("data/assets/textures/animations/player/player_dead.png");

	skelyIdle = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_idle.png", 24, 24);
	skelyRun = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_run.png", 24, 24);
	skelyAttack = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_attack.png", 24, 24);
	skelyStunned = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_stunned.png", 24, 24);
	skelyDead = Loader::loadTexture("data/assets/textures/animations/skeleton/skely_dead.png");

	skelyIdle_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_idle_pow.png", 24, 24);
	skelyRun_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_run_pow.png", 24, 24);
	skelyAttack_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_attack_pow.png", 24, 24);
	skelyStunned_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_stunned_pow.png", 24, 24);
	skelyDead_pow = Loader::loadTexture("data/assets/textures/animations/skeleton/skely_dead_pow.png");

	skelyIdleSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_idle.png", 24, 24);
	skelyRunSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_run.png", 24, 24);
	skelyAttackSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_attack.png", 24, 24);
	skelyStunnedSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_stunned.png", 24, 24);
	skelyDeadSW = Loader::loadTexture("data/assets/textures/animations/skeleton_sword/skely_dead.png");

	skelyIdleSW_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_idle_pow.png", 24, 24);
	skelyRunSW_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_run_pow.png", 24, 24);
	skelyAttackSW_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_attack_pow.png", 24, 24);
	skelyStunnedSW_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_stunned_pow.png", 24, 24);
	skelyDeadSW_pow = Loader::loadTexture("data/assets/textures/animations/skeleton_sword/skely_dead_pow.png");

	//TILEMAP
	vector<string> keys{ "O0","O0","O0","O1","O2","O3","O4","O5","O6","O7","O8","#0","#1","#2","#3","#4","#5","#6","#7" };
	Loader::loadTileMap(tilemap, keys, "data/assets/textures/tileset/dungeon_tileset_v.png", 16);

	//SCENE OBJECTS
	doorClosed = Loader::loadTexture("data/assets/textures/scene_objects/door/closed.png");
	doorOpen = Loader::loadSpriteSheet("data/assets/textures/scene_objects/door/open.png", 32, 16);

	// ITEMS
	key = Loader::loadTexture("data/assets/textures/items/key.png");

	//GUI
	mouse = Loader::loadTexture("data/assets/textures/gui/mouse.png")->copyToImage();

}
