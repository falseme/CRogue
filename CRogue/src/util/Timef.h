#pragma once

#include <SFML/System/Clock.hpp>

using namespace sf;

class Timef {
private:
	static Clock clock;
	static float dt; // delta time
	static int factor;
public:
	static void start(int factor);
	static void update();
	static float deltaTime();
	static float deltaTimeFactor();
};

