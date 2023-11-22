#include "Render.h"

Render* Render::instance = NULL;

Render* Render::get() {
	if (instance == NULL)
		instance = new Render();
	return instance;
}

void Render::render() {

	for (Tile t : tileset)
		t.render(RWindow::get());

}

void Render::loadTileSet() {

	for (int i = 0; i < 6; i++) {
		tileset.push_back(Tile(i, 0, Assets::Tileset->copyToImage()));
	}

}