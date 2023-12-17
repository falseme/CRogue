#include "Animation.h"

#include <util/Timef.h>

Animation::Animation() {
	timeSecs = 0;
	repeat = true;
	frameTime = 0;
	currentFrame = 0;
	currentTime = 0;
	end = false;
}

Animation::Animation(float timeSecs, vector<Texture*> frames, bool repeat) {
	this->timeSecs = timeSecs;
	this->frames = frames;
	this->repeat = repeat;
	currentFrame = 0;
	currentTime = 0;
	frameTime = timeSecs / frames.size();
	end = false;
}

Animation::Animation(Texture* uniqueFrame) {
	timeSecs = 1;
	frames.push_back(uniqueFrame);
	repeat = true;
	currentFrame = 0;
	currentTime = 0;
	frameTime = timeSecs / frames.size();
	end = false;
}

Texture* Animation::getFrame() {

	return frames[(int)currentFrame];

}

void Animation::play() {

	currentTime += Timef::deltaTime();

	if (currentTime >= frameTime) {
		currentTime = 0;
		currentFrame++;
	}

	if (currentFrame >= frames.size()) {
		currentFrame = repeat ? 0 : frames.size() - 1;
		end = true;
	}

}

void Animation::reset() {
	currentFrame = 0;
	end = false;
}

bool Animation::ended() const {
	return end;
}