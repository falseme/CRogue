#pragma once

#include <list>
#include "UIComponent.h"

using namespace std;

class Panel {
private:
	Vector2f worldPosition;
	list<UIComponent*> components;
	Color backgroundColor;
public:
	Panel();
	Panel(Vector2f pos);
	Panel(Vector2f pos, Color bgColor);
	void update(Vector2f mousePosition);
	void draw(RWindow* render);
	void addComponent(UIComponent* component);
	void removeComponent(UIComponent* component);
	void move(Vector2f delta);
	Vector2f getWorldPosition();
};

