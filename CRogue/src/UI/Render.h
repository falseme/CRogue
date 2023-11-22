#pragma once

#include "RWindow.h"
#include "../Scene/Tile.h"
#include <list>
#include "../assets/Assets.h"

class Render {
private:
	static Render* instance;
	list<Tile> tileset;
public:
	void loadTileSet();
	void render();
	static Render* get();
};

