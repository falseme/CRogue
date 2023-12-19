#pragma once

#include "UIComponent.h"

using namespace std;

class Label : public UIComponent {
public:
	Label(Vector2f pos, string text, int size, bool title = false, bool centerAlignX = false, bool centerAlignY = false);
	void update(Vector2f mousePosition, Vector2f panelPosition) override;
	void draw(RWindow* render) override;
	void setPosition(Vector2f position) override;
	Vector2f getPosition() override;
	void move(Vector2f delta) override;
protected:
	Text text;
};

