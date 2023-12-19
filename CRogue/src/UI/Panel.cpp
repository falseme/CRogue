#include "Panel.h"

Panel::Panel() {
	backgroundColor = Color(0, 0, 0, 0);
}

Panel::Panel(Vector2f pos) {
	worldPosition = pos;
	backgroundColor = Color(0, 0, 0, 0);
}

Panel::Panel(Vector2f pos, Color bgColor) {
	worldPosition = pos;
	backgroundColor = bgColor;
}

void Panel::update(Vector2f mousePosition) {
	for (UIComponent* component : components) {
		component->update(mousePosition, worldPosition);
	}
}

void Panel::draw(RWindow* render) {
	RectangleShape background(Vector2f(render->getSize().x, render->getSize().y));
	background.setFillColor(backgroundColor);
	background.setPosition(worldPosition);
	render->draw(background);
	for (UIComponent* component : components) {
		component->draw(render);
	}
}

void Panel::addComponent(UIComponent* component) {
	component->setPosition(component->getPosition() + worldPosition);
	components.push_back(component);
}

void Panel::removeComponent(UIComponent* component) {
	components.remove(component);
	delete component;
}

void Panel::move(Vector2f delta) {
	worldPosition += delta;
	for (UIComponent* comp : components) {
		comp->move(delta);
	}
}

Vector2f Panel::getWorldPosition() {
	return worldPosition;
}
