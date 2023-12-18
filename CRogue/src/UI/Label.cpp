#include "Label.h"

#include <assets/Assets.h>

Label::Label(Vector2f pos, string text, int size, bool title, bool centerAlignX, bool centerAlignY) {
	this->text.setFont(title ? Assets::titleFont : Assets::defaultFont);
	this->text.setString(text);
	this->text.setPosition(pos);
	this->text.setCharacterSize(size);
	this->text.setOrigin(centerAlignX ? this->text.getLocalBounds().width / 2 : 0, centerAlignY ? this->text.getLocalBounds().height / 2 : 0);
	this->text.setFillColor(Color(20, 10, 15));
}

void Label::update(Vector2f mousePosition, Vector2f panelPosition) {

}

void Label::draw(RWindow* render) {
	render->draw(text);
}

void Label::setPosition(Vector2f position) {
	text.setPosition(position);
}

Vector2f Label::getPosition() {
	return text.getPosition();
}
