#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

class Animation {
private:
	vector<Texture*> frames;
	float timeSecs, frameTime, currentFrame, currentTime;
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