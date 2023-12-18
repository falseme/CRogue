#pragma once

#include "Label.h"
#include "scene/SceneManager.h"

class Button : public UIComponentCallback<void()> {
public:
	Button(Vector2f pos, string text, int fontSize);
	void update(Vector2f mousePosition, Vector2f panelPosition) override;
	void draw(RWindow* render) override;

	void setPosition(Vector2f position) override;
	Vector2f getPosition() override;
protected:
	bool pressed;
	Text text;
	Color backgroundColor;
	RectangleShape background;
};

