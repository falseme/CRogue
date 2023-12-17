#include <util/Timef.h>

Clock Timef::clock;
float Timef::dt;
int Timef::factor;

void Timef::start(int factor) {
	Timef::factor = factor;
	clock.restart();
}

void Timef::update() {
	dt = clock.restart().asSeconds();
}

float Timef::deltaTime() {
	return dt;
}

float Timef::deltaTimeFactor() {
	return dt * factor;
}

