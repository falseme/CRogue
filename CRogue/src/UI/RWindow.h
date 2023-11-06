#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class RWindow : public RenderWindow {
private:
	static RWindow* instance;
	RWindow();
public:
	static RWindow* get();
	static void init();
	static void draw();
	void loop();
};

