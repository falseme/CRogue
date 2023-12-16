#include "Animation.h"

Animation::Animation() {
	timeSecs = 0;
	frameTime = 0;
	currentFrame = 0;
	end = false;
}

Animation::Animation(float timeSecs, Texture** frames, int framesCount) {
	this->timeSecs = timeSecs;
	frameTime = 0;
	currentFrame = 0;
	for (int i = 0; i < framesCount; i++)
		addTexture(frames[i]);
	end = false;
}

Animation::Animation(Texture* uniqueFrame) {
	timeSecs = 1;
	currentFrame = 0;
	addTexture(uniqueFrame);
	end = false;
}

void Animation::addTexture(Texture* tex) {
	frames.push_back(tex);
	frameTime = frames.size() / (float)FPS;
	frameTime /= timeSecs;
}

Texture* Animation::getFrame() {

	return frames[(int)currentFrame];

}

void Animation::play() {

	currentFrame += frameTime;
	if (currentFrame >= frames.size()) {
		currentFrame = 0;
		end = true;
	}

}

void Animation::reset() {
	currentFrame = 0;
	end = false;
}

bool Animation::ended() {
	return end;
}