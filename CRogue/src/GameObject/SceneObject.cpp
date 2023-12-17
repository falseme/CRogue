#include "SceneObject.h"

SceneObject::SceneObject(Vector2f pos, vector<Animation> anim, BoxCollider collider) : GameObject(pos, "sceneObject", anim, collider) {

}

void SceneObject::update() {

	animations[currentAnimation].play();

}

void SceneObject::onCollision(BoxCollider other, Vector2f delta) {}
