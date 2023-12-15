#include "RWindow.h"

#include <util/Mathv.h>
#include <assets/Assets.h>

RWindow* RWindow::instance = NULL;

RWindow::RWindow() : RenderWindow(VideoMode(800, 600), "CROGUE [/]", sf::Style::Close) {

	View v = getView();
	v.setCenter(100, 100);
	v.zoom(0.5f);
	setView(v);

	Cursor cursor;
	if (cursor.loadFromPixels(Assets::mouse.getPixelsPtr(), { 20,20 }, { 0,0 }))
		setMouseCursor(cursor);

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
