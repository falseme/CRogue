#include "LevelScene1.h"

#include "../../GameObject/Player.h"

LevelScene1::LevelScene1() {

}

void LevelScene1::init() {

	loadLevel(1);

	Animation playerAnimation(0.85f, Assets::playerIdle_anim, 4);
	addGameObject(new Player(Vector2f(10, 10), playerAnimation, 10, 5));

}

void LevelScene1::update() {

	for (GameObject* go : gameObjects) {
		go->update();
	}

}