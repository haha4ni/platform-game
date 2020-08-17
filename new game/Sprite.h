/**
  ******************************************************************************
  * @file     Sprite.h
  * @version
  * @brief    單張圖片的讀取，分割Sprite，動圖會一次存很多個數據
  *			  只負責精靈圖的繪畫
  ******************************************************************************
  */

#ifndef SPRITE_H
#define SPRITE_H

#include "Graphics.h"

class Sprite
{
public:
	Sprite();
	Sprite(const std::string &filePath, int blockX, int blockY, int blockWidth, int blockHeight);
	//~Sprite();

	void loadImage(const std::string& filePath, int blockX, int blockY, int blockWidth, int blockHeight);
	virtual void update();
	virtual void draw(int x, int y, SDL_RendererFlip flip);
protected:
	//圖檔資訊
	SDL_Texture* spriteSheet_ = NULL;
	SDL_Rect blockRect_ = SDL_Rect{0,0,0,0};
};

#endif //SPRITE_H
