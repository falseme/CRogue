#pragma once

#include <functional>

#include <SFML/Graphics.hpp>
#include "RWindow.h"

using namespace sf;

class UIComponent {
protected:
	Color fillColor, hoverColor, pressedColor;
public:
	virtual void update(Vector2f mousePosition, Vector2f panelPosition) = 0;
	virtual void draw(RWindow* render) = 0;
	virtual void setPosition(Vector2f position) = 0;
	virtual Vector2f getPosition() = 0;
	virtual void move(Vector2f delta) = 0;
};

template <typename T>
class UIComponentCallback : public UIComponent {
protected:
	std::function<T> callback;
public:
	void setCallback(std::function<T> newCallback) {
		callback = newCallback;
	}
};

