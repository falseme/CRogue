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
	bool end;
	bool repeat;
public:
	Animation();
	Animation(float timeSecs, vector<Texture*> frames, bool repeat = true);
	Animation(Texture* uniqueFrame);

	Texture* getFrame();

	void play();
	void reset();

	bool ended() const;
};