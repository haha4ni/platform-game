#ifndef SPRITE_H
#define SPRITE_H

#include "Graphics.h"

class Sprite
{
public:
	Sprite();
	Sprite(const std::string &filePath, int blockX, int blockY, int blockWidth, int blockHeight);
	~Sprite();

	virtual void update();
	virtual void draw(int x, int y, SDL_RendererFlip flip);
protected:
	//載入的圖檔
	SDL_Texture* spriteSheet_;
	//block座標 起始點x y 單塊的長寬
	SDL_Rect blockRect_;
};

#endif //SPRITE_H
