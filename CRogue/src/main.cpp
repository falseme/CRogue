#include "UI/RWindow.h"
#include "World/World.h"

void loop(RWindow* r) {

	while (r->isOpen()) {

		Event event;
		while (r->pollEvent(event)) {
			if (event.type == Event::Closed)
				r->close();
		}

		r->clear();
		World::update();
		World::draw(r);
		r->display();

	}

}

int main() {

	World::loadScene();

	loop(RWindow::get());

	return 0;
}