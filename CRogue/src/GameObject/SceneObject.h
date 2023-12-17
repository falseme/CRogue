#pragma once

#include "GameObject.h";

class SceneObject : public GameObject {
public:
	SceneObject(Vector2f pos, vector<Animation> anim, BoxCollider collider);

	void update() override;
	void onCollision(BoxCollider other, Vector2f delta) override;

};

