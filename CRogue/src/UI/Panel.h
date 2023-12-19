#pragma once

#include <list>
#include "UIComponent.h"

using namespace std;

class Panel {
private:
	Vector2f worldPosition;
	list<UIComponent*> components;
public:
	Panel();
	Panel(Vector2f pos);
	void update(Vector2f mousePosition);
	void draw(RWindow* render);
	void addComponent(UIComponent* component);
	void removeComponent(UIComponent* component);
	void move(Vector2f delta);
	Vector2f getWorldPosition();
};

