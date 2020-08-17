/**
  ******************************************************************************
  * @file     Sprite.h
  * @version
  * @brief    ��i�Ϥ���Ū���A����Sprite�A�ʹϷ|�@���s�ܦh�Ӽƾ�
  *			  �u�t�d���F�Ϫ�ø�e
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
	//���ɸ�T
	SDL_Texture* spriteSheet_ = NULL;
	SDL_Rect blockRect_ = SDL_Rect{0,0,0,0};
};

#endif //SPRITE_H
