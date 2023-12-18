#include <UI/RWindow.h>
#include <Scene/SceneManager.h>
#include <assets/Assets.h>
#include <util/Timef.h>

static void loop(RWindow* r) {

	View view = r->getDefaultView();

	while (r->isOpen()) {

		Event event;
		while (r->pollEvent(event)) {
			if (event.type == Event::Closed) {
				r->close();
			}
			if (event.type == Event::MouseMoved) {
				r->setMousePosition(Vector2f(event.mouseMove.x, event.mouseMove.y));
			}
			if (event.type == Event::MouseEntered)
				r->setSwordCursor();
		}

		Timef::update();

		r->clear(Color(37, 19, 26));
		SceneManager::update(r->getMousePosition());
		SceneManager::draw(r);
		r->display();

	}

}

int main() {

	Assets::load();
	Timef::start(60);

	SceneManager::init();

	loop(RWindow::get());

	return 0;
}