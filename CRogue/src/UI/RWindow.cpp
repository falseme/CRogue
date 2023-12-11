#include "RWindow.h"

#include "../util/Mathv.h"

RWindow* RWindow::instance = NULL;

RWindow::RWindow() : RenderWindow(VideoMode(800, 600), "CROGUE [/]", sf::Style::Close) {

	View v = getView();
	v.setCenter(100, 100);
	v.zoom(0.5f);
	setView(v);

}

RWindow* RWindow::get() {
	if (!instance)
		instance = new RWindow();
	return instance;
}

Vector2f RWindow::getMousePosition() {
	return mousePosition;
}

void RWindow::setMousePosition(Vector2f pos) {
	mousePosition = pos;
}

void RWindow::follow(Vector2f pos, int offset) {

	View v = getView();

	if (Mathv::distance(pos, v.getCenter()) > offset) {
		Vector2f delta = pos - v.getCenter();
		Mathv::normalizeAndScale(delta, offset);
		Vector2f vMove = pos - v.getCenter() - delta;
		v.setCenter(v.getCenter() + vMove);
	}

	setView(v);

}
