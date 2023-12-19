#include "Panel.h"

Panel::Panel() {

}

Panel::Panel(Vector2f pos) {
	worldPosition = pos;
}

void Panel::update(Vector2f mousePosition) {
	for (UIComponent* component : components) {
		component->update(mousePosition, worldPosition);
	}
}

void Panel::draw(RWindow* render) {
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
