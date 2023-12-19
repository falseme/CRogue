#include "RWindow.h"

#include <util/Mathv.h>
#include <assets/Assets.h>

RWindow* RWindow::instance = nullptr;

RWindow::RWindow() : RenderWindow(VideoMode(800, 600), "CROGUE [/]", sf::Style::Close) {

	setSwordCursor();

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

void RWindow::setSwordCursor() {

	Cursor cursor;
	if (cursor.loadFromPixels(Assets::mouse->copyToImage().getPixelsPtr(), { 20,20 }, { 0,0 }))
		setMouseCursor(cursor);

}
