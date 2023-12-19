#pragma once

#include "UIComponent.h"
#include <animation/Animation.h>

class AnimatedSpriteImage : public UIComponent {
public:
	AnimatedSpriteImage(Animation anim, Vector2f pos, Vector2f scale, Vector2f origin);
	void update(Vector2f mousePosition, Vector2f panelPosition);
	void draw(RWindow* render);
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void move(Vector2f delta);
private:
	Sprite sprite;
	Animation animation;
};

