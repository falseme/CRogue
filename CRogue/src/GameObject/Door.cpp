#include "Door.h"

#include "Player.h"
#include <scene/SceneManager.h>

Door::Door(Vector2f pos) : SceneObject(pos, { Animation(Assets::doorClosed), Animation(0.6f, Assets::doorOpen, false) }, BoxCollider(Vector2f(16, 16), Vector2f(0, 0))) {
	open = false;
}

void Door::update() {

	if (open && animations[currentAnimation].ended())
		collider.setSize(Vector2f(0, 0));

	animations[currentAnimation].play();
	sprite.setTexture(*animations[currentAnimation].getFrame());

}

void Door::onCollision(BoxCollider other, Vector2f delta) {

	Player* pl = (Player*)SceneManager::getCurrentScene()->find("player");
	if (pl == nullptr)
		return;
	if (pl->getCollider() != other)
		return;

	if (pl->hasItem(Player::KEY_ID)) {
		pl->removeInventoryItem(Player::KEY_ID);
		open = true;
		currentAnimation = 1;
	}

}
