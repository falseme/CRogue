#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

class Animation {
private:
	static const int FPS = 60; // testing will delete this later
	vector<Texture*> frames;
	float frameTime, timeSecs;
	float currentFrame;
public:
	Animation();
	Animation(float timeSecs);
	void addTexture(Texture* tex);
	Texture* getFrame();
	void play();
};