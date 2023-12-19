#pragma once

#include "UIComponent.h"

class SpriteImage : public UIComponent {
public:
	SpriteImage(Texture* texture, Vector2f pos, Vector2f scale, Vector2f origin);

	void setTexture(Texture* tex);

	void update(Vector2f mousePosition, Vector2f panelPosition);
	void draw(RWindow* render);
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void move(Vector2f delta) override;
private:
	Sprite sprite;
};

