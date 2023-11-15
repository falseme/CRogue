#include "RWindow.h"

RWindow* RWindow::instance = NULL;

RWindow::RWindow() : RenderWindow(VideoMode(800, 600), "CROGUE [/]") {

}

RWindow* RWindow::get() {
	if (!instance)
		instance = new RWindow();
	return instance;
}


