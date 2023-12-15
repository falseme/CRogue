#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class RWindow : public RenderWindow {
private:
	Vector2f mousePosition;
	static RWindow* instance;
	RWindow();
public:
	static RWindow* get();
	Vector2f getMousePosition();
	void setMousePosition(Vector2f pos);
};

