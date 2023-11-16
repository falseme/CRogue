#include "Animation.h"

Animation::Animation() {
	timeSecs = 0;
	frameTime = 0;
	currentFrame = 0;
}

Animation::Animation(float timeSecs) {
	this->timeSecs = timeSecs;
	frameTime = 0;
	currentFrame = 0;
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
	if (currentFrame >= frames.size())
		currentFrame = 0;

}