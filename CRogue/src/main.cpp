#include "UI/RWindow.h"
#include "Scene/SceneManager.h"
#include "assets/Assets.h"
#include "UI/Render.h"

void loop(RWindow* r) {

	r->setFramerateLimit(60);

	while (r->isOpen()) {

		Event event;
		while (r->pollEvent(event)) {
			if (event.type == Event::Closed)
				r->close();
		}

		r->clear();
		SceneManager::update();
		Render::get()->render();
		SceneManager::draw(r);
		r->display();

	}

}

int main() {

	Assets::load();

	Render::get()->loadTileSet(); // test
	SceneManager::loadScene();

	loop(RWindow::get());

	return 0;
}