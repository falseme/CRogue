#include "Loader.h"

Texture* Loader::loadTexture(string path) {

	Texture* tex = new Texture();
	if (tex->loadFromFile(path)) {
		return tex;
	}
	else {
		delete tex;
		return nullptr;
	}

}

vector<Texture*> Loader::loadSpriteSheet(string path, int spriteWidth, int spriteHeight) {

	vector<Texture*> v;

	Image spriteSheet = Loader::loadTexture(path)->copyToImage();
	for (int i = 0; i < spriteSheet.getSize().x; i += spriteWidth) {
		Texture* t = new Texture();
		if (t->loadFromImage(spriteSheet, IntRect(i, 0, spriteWidth, spriteHeight)))
			v.push_back(t);
		else
			delete t;
	}

	return v;

}

void Loader::loadTileMap(map<string, vector<Texture*>>& tilemap, const vector<string>& keys, string path, int tileSize) {

	Image tileset = Loader::loadTexture(path)->copyToImage();

	for (int j = 0; j < tileset.getSize().y - 16; j += 16) {
		for (int i = 0; i < tileset.getSize().x; i += 16) {

			Texture* tex = new Texture();
			if (tex->loadFromImage(tileset, IntRect(i, j, 16, 16)))
				tilemap[keys[j / 16]].push_back(tex);
			else
				delete tex;

		}
	}

}
