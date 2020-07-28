#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <vector>
#include "sprite.h"
#include <SDL.h>

//紀錄動畫有幾幀 每塊的位置 每塊所花的時間(幀)
typedef struct
{
	int frameNum;
	std::vector<SDL_Rect> blockRects;
	std::vector<int> blocksFrameTime;
}AnimatedStream;

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite();
	AnimatedSprite(const std::string &filePath);
	~AnimatedSprite();

	void addAnimation(std::string name, int frameNum, int* blocksFrameTime, int blockX, int blockY, int blockWidth, int blockHeight);
	void changeAnimation(std::string name);

	void update();
	void draw(int x, int y, SDL_RendererFlip flip);

private:
	//紀錄每個動作的資料
	std::map<std::string, AnimatedStream> animatedStreams_;
	std::string currentAnimation_;
	int frameIndex_;
	int frameTimeElapsed_;

	bool visible_;
};

#endif // !ANIMATED_SPRITE_H