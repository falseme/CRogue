#include "Loader.h"

Texture* Loader::loadTexture(string path) {

	Texture* tex = new Texture();
	if (tex->loadFromFile(path)) {
		return tex;

	}
	else {
		delete tex;
		return NULL;
	}

}