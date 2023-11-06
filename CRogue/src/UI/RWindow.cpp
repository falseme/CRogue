#include "RWindow.h"

RWindow *RWindow::instance = NULL;

RWindow::RWindow() : RenderWindow(VideoMode(800,600), "CROGUE [/]") {

}

RWindow* RWindow::get() {
	if (!instance)
		instance = new RWindow();
	return instance;
}

void RWindow::init() {
	get()->loop();
}

void RWindow::draw() {

}

void RWindow::loop() {

	while (isOpen()) {

		Event event;
		while (pollEvent(event)) {
			if (event.type == Event::Closed)
				close();
		}

		clear();
		draw();
		display();

	}

}