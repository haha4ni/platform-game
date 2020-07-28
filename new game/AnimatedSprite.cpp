#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(){}
AnimatedSprite::~AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(const std::string &filePath)
	:Sprite(filePath, 0, 0, 10, 10)
{

}

//簡易版 每格大小一樣
void AnimatedSprite::addAnimation(std::string name, int frameNum, int* blocksFrameTime, int blockX, int blockY, int blockWidth, int blockHeight)
{
	AnimatedStream tmpAnimatedStream;
	tmpAnimatedStream.frameNum = frameNum;
	
	SDL_Rect tmpRect = {0,0,0,0};
	for (int i = 0; i < frameNum; i++)
	{
		//記錄每一幀的起始座標與塊寬長
		tmpRect = { (blockX+i)*blockWidth, blockY, blockWidth, blockHeight };
		tmpAnimatedStream.blockRects.push_back(tmpRect);
	}

	for (int i = 0; i < frameNum; i++)
	{
		tmpAnimatedStream.blocksFrameTime.push_back(blocksFrameTime[i]);
	}

	animatedStreams_[name] = tmpAnimatedStream;
}

void AnimatedSprite::changeAnimation(std::string animationName)
{
	if (this->currentAnimation_ != animationName) {
		this->currentAnimation_ = animationName;
		this->frameIndex_ = 0;
		this->frameTimeElapsed_ = 0;

		blockRect_ = animatedStreams_[currentAnimation_].blockRects[this->frameIndex_];
	}
}

void AnimatedSprite::update()
{
	this->frameTimeElapsed_ += 1;
	if (this->frameTimeElapsed_ >= animatedStreams_[currentAnimation_].blocksFrameTime[frameIndex_])
	{
		this->frameTimeElapsed_ = 0;
		this->frameIndex_ += 1;
		if (frameIndex_ >= animatedStreams_[currentAnimation_].frameNum)
		{
			this->frameIndex_ = 0;
		}
		this->blockRect_ = animatedStreams_[currentAnimation_].blockRects[frameIndex_];
	}
}

void AnimatedSprite::draw(int x, int y, SDL_RendererFlip flip)
{
	Sprite::draw(x, y, flip);
}