#include "Ladder.h"

#include <assets/Assets.h>
#include <scene/SceneManager.h>
#include "Player.h"

Ladder::Ladder(Vector2f pos) : SceneObject(pos, {Animation(Assets::ladder)}, BoxCollider(Vector2f(6, 6), Vector2f(0,-5))) {
}

void Ladder::onCollision(BoxCollider other, Vector2f delta) {

	Player* pl = (Player*)SceneManager::getCurrentScene()->find("player");
	if (pl == nullptr)
		return;
	if (pl->getCollider() != other)
		return;

	SceneManager::gotoNextLevel();

}
