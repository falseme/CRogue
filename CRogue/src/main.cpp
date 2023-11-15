#include "UI/RWindow.h"
#include "Scene/SceneManager.h"
#include "assets/Assets.h"

void loop(RWindow* r) {

	while (r->isOpen()) {

		Event event;
		while (r->pollEvent(event)) {
			if (event.type == Event::Closed)
				r->close();
		}

		r->clear();
		SceneManager::update();
		SceneManager::draw(r);
		r->display();

	}

}

int main() {

	Assets::load();

	SceneManager::loadScene();

	loop(RWindow::get());

	return 0;
}