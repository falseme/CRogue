#include "TestGameObject.h"

#include <iostream>
using namespace std;

TestGameObject::TestGameObject(Vector2f pos, Texture* tex) : GameObject(pos, tex) {

}

void TestGameObject::update() { // JUST TESTING
	move(Vector2f(0.1f, 0.f));
	sprite.setPosition(pos);
}
