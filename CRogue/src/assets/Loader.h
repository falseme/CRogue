#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Loader {
public:
	static Texture* loadTexture(string path);
	static vector<Texture*> loadSpriteSheet(string path, int spriteSize);
	static void loadTileMap(map<string, vector<Texture*>>& tilemap, const vector<string>& keys, string path, int tileSize);
};

