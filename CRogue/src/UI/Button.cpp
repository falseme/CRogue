#include "Button.h"

#include <SFML/Window/Mouse.hpp>

Button::Button(Vector2f pos, string text, int fontSize) {

	pressed = false;

	fillColor = Color(130, 95, 115);
	hoverColor = Color(175, 145, 170);
	pressedColor = Color(100, 70, 85);
	backgroundColor = fillColor;

	this->text.setFont(Assets::defaultFont);
	this->text.setString(text);
	this->text.setCharacterSize(fontSize);
	this->text.setPosition(pos);
	this->text.setOrigin(this->text.getLocalBounds().width / 2, this->text.getLocalBounds().height / 2);
	this->text.setFillColor(Color(30, 20, 25));

	background.setSize(Vector2f(this->text.getLocalBounds().width + 10, this->text.getLocalBounds().height + 12));
	background.setPosition(this->text.getPosition());
	background.setOrigin(this->text.getOrigin().x * background.getSize().x / this->text.getLocalBounds().width, this->text.getOrigin().y * background.getSize().y / this->text.getLocalBounds().height);
	background.setOutlineColor(pressedColor);
	background.setOutlineThickness(2);
}

void Button::update(Vector2f mousePosition, Vector2f panelPosition) {

	bool inx = mousePosition.x > background.getPosition().x - background.getOrigin().x - panelPosition.x && mousePosition.x < background.getPosition().x + background.getLocalBounds().width - background.getOrigin().x - panelPosition.x;
	bool iny = mousePosition.y > background.getPosition().y - background.getOrigin().y - panelPosition.y && mousePosition.y < background.getPosition().y + background.getLocalBounds().height - background.getOrigin().y - panelPosition.y;
	bool in = inx && iny;

	if (in) {
		backgroundColor = pressed ? pressedColor : hoverColor;
		if (Mouse::isButtonPressed(Mouse::Left) && !pressed) {
			pressed = true;
		}
		else if (!Mouse::isButtonPressed(Mouse::Left) && pressed) {
			if (callback) callback();
			pressed = false;
		}
	}
	else {
		backgroundColor = fillColor;
		pressed = false;
	}

}

void Button::draw(RWindow* render) {
	background.setFillColor(backgroundColor);
	render->draw(background);
	render->draw(text);
}

void Button::setPosition(Vector2f position) {
	text.setPosition(position);
	background.setPosition(position);
}

Vector2f Button::getPosition() {
	return text.getPosition();
}

void Button::move(Vector2f delta) {
	text.move(delta);
	background.move(delta);
}

