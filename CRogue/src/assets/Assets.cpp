#include "Assets.h"

vector<Texture*> Assets::playerIdle;
vector<Texture*> Assets::playerRun;
vector<Texture*> Assets::playerAttack;
vector<Texture*> Assets::playerStunned;
vector<Texture*> Assets::playerHeal;
Texture* Assets::playerDead = nullptr;

vector<Texture*> Assets::skelyIdle;
vector<Texture*> Assets::skelyRun;
vector<Texture*> Assets::skelyAttack;
vector<Texture*> Assets::skelyStunned;
vector<Texture*> Assets::skelyHeal;
Texture* Assets::skelyDead = nullptr;

vector<Texture*> Assets::skelyIdle_pow;
vector<Texture*> Assets::skelyRun_pow;
vector<Texture*> Assets::skelyAttack_pow;
vector<Texture*> Assets::skelyStunned_pow;
vector<Texture*> Assets::skelyHeal_pow;
Texture* Assets::skelyDead_pow = nullptr;

vector<Texture*> Assets::skelyIdleSW;
vector<Texture*> Assets::skelyRunSW;
vector<Texture*> Assets::skelyAttackSW;
vector<Texture*> Assets::skelyStunnedSW;
vector<Texture*> Assets::skelyHealSW;
Texture* Assets::skelyDeadSW = nullptr;

vector<Texture*> Assets::skelyIdleSW_pow;
vector<Texture*> Assets::skelyRunSW_pow;
vector<Texture*> Assets::skelyAttackSW_pow;
vector<Texture*> Assets::skelyStunnedSW_pow;
vector<Texture*> Assets::skelyHealSW_pow;
Texture* Assets::skelyDeadSW_pow = nullptr;

map<string, vector<Texture*>> Assets::tilemap;

Texture* Assets::ladder = nullptr;
Texture* Assets::doorClosed = nullptr;
vector<Texture*> Assets::doorOpen;
vector<Texture*> Assets::flag;
vector<Texture*> Assets::torch;
vector<Texture*> Assets::torch_side;

Texture* Assets::key = nullptr;
Texture* Assets::healthPotion = nullptr;
Texture* Assets::healthPotion_small = nullptr;

vector<Texture*> Assets::WASD;
vector<Texture*> Assets::H;
vector<Texture*> Assets::ESC;
vector<Texture*> Assets::TAB;
Texture* Assets::mouse = nullptr;

Font Assets::defaultFont;
Font Assets::titleFont;

Texture* Assets::heart;
Texture* Assets::heart_half;
Texture* Assets::heart_empty;

void Assets::load() {

	//ENTITIES

	playerIdle = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_idle.png", 24, 24);
	playerRun = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_run.png", 24, 24);
	playerAttack = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_attack.png", 24, 24);
	playerStunned = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_stunned.png", 24, 24);
	playerHeal = Loader::loadSpriteSheet("data/assets/textures/animations/player/player_heal.png", 24, 24);
	playerDead = Loader::loadTexture("data/assets/textures/animations/player/player_dead.png");

	skelyIdle = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_idle.png", 24, 24);
	skelyRun = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_run.png", 24, 24);
	skelyAttack = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_attack.png", 24, 24);
	skelyStunned = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_stunned.png", 24, 24);
	skelyHeal = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_heal.png", 24, 24);
	skelyDead = Loader::loadTexture("data/assets/textures/animations/skeleton/skely_dead.png");

	skelyIdle_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_idle_pow.png", 24, 24);
	skelyRun_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_run_pow.png", 24, 24);
	skelyAttack_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_attack_pow.png", 24, 24);
	skelyStunned_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_stunned_pow.png", 24, 24);
	skelyHeal_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton/skely_heal_pow.png", 24, 24);
	skelyDead_pow = Loader::loadTexture("data/assets/textures/animations/skeleton/skely_dead_pow.png");

	skelyIdleSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_idle.png", 24, 24);
	skelyRunSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_run.png", 24, 24);
	skelyAttackSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_attack.png", 24, 24);
	skelyStunnedSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_stunned.png", 24, 24);
	skelyHealSW = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_heal.png", 24, 24);
	skelyDeadSW = Loader::loadTexture("data/assets/textures/animations/skeleton_sword/skely_dead.png");

	skelyIdleSW_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_idle_pow.png", 24, 24);
	skelyRunSW_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_run_pow.png", 24, 24);
	skelyAttackSW_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_attack_pow.png", 24, 24);
	skelyStunnedSW_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_stunned_pow.png", 24, 24);
	skelyHealSW_pow = Loader::loadSpriteSheet("data/assets/textures/animations/skeleton_sword/skely_heal_pow.png", 24, 24);
	skelyDeadSW_pow = Loader::loadTexture("data/assets/textures/animations/skeleton_sword/skely_dead_pow.png");

	//TILEMAP
	vector<string> keys{ "O0","O0","O0","O1","O2","O3","O4","O5","O6","O7","O8","#0","#1","#2","#3","#4","#5","#6","#7" };
	Loader::loadTileMap(tilemap, keys, "data/assets/textures/tileset/dungeon_tileset_v.png", 16);

	//SCENE OBJECTS
	ladder = Loader::loadTexture("data/assets/textures/scene_objects/ladder.png");
	doorClosed = Loader::loadTexture("data/assets/textures/scene_objects/door_closed.png");
	doorOpen = Loader::loadSpriteSheet("data/assets/textures/scene_objects/door_open.png", 32, 16);
	flag = Loader::loadSpriteSheet("data/assets/textures/scene_objects/flag.png", 16,16);
	torch = Loader::loadSpriteSheet("data/assets/textures/scene_objects/torch.png", 16, 16);
	torch_side = Loader::loadSpriteSheet("data/assets/textures/scene_objects/torch_side.png", 16, 16);

	// ITEMS
	key = Loader::loadTexture("data/assets/textures/items/key.png");
	healthPotion = Loader::loadTexture("data/assets/textures/items/health.png");
	healthPotion_small = Loader::loadTexture("data/assets/textures/items/health_small.png");

	//GUI
	WASD = Loader::loadSpriteSheet("data/assets/textures/gui/keyboard/WASD.png", 63, 42);
	H = Loader::loadSpriteSheet("data/assets/textures/gui/keyboard/H.png", 19, 21);
	ESC = Loader::loadSpriteSheet("data/assets/textures/gui/keyboard/ESC.png", 41, 21);
	TAB = Loader::loadSpriteSheet("data/assets/textures/gui/keyboard/TAB.png", 33, 21);
	mouse = Loader::loadTexture("data/assets/textures/gui/mouse.png");
	heart = Loader::loadTexture("data/assets/textures/gui/heart2.png");
	heart_half = Loader::loadTexture("data/assets/textures/gui/heart1.png");
	heart_empty = Loader::loadTexture("data/assets/textures/gui/heart0.png");

	//FONT
	defaultFont.loadFromFile("data/assets/fonts/dogicapixelbold.ttf");
	titleFont.loadFromFile("data/assets/fonts/Pixelmania.ttf");

}
