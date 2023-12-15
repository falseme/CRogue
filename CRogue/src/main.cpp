#include <UI/RWindow.h>
#include <Scene/SceneManager.h>
#include <assets/Assets.h>

static void loop(RWindow* r) {

	r->setFramerateLimit(60);

	View view = r->getDefaultView();

	while (r->isOpen()) {

		Event event;
		while (r->pollEvent(event)) {
			if (event.type == Event::Closed) {
				r->close();
			}
			if (event.type == Event::MouseButtonPressed) {
				r->setMousePosition(Vector2f(event.mouseButton.x, event.mouseButton.y));
			}
		}

		r->clear(Color(37, 19, 26));
		SceneManager::update();
		SceneManager::draw(r);
		r->display();

	}

}

int main() {

	Assets::load();

	SceneManager::init();

	loop(RWindow::get());

	return 0;
}