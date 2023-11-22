#include "World.h"

Scene *World::mainScene = NULL;

void World::loadScene() {
	mainScene = new TestScene(); // TEMP // TESTING
	mainScene->init();
}

void World::update() {
	mainScene->update();
}

void World::draw(RWindow* render) {
	mainScene->draw(render);
}