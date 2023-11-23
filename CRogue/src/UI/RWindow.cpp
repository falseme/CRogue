#include "RWindow.h"

RWindow* RWindow::instance = NULL;

RWindow::RWindow() : RenderWindow(VideoMode(800, 600), "CROGUE [/]") {

	View v = getView();
	v.setCenter(0,0);
	v.zoom(0.5f);
	setView(v);

}

RWindow* RWindow::get() {
	if (!instance)
		instance = new RWindow();
	return instance;
}


