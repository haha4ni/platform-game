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
	//���J������
	SDL_Texture* spriteSheet_;
	//block�y�� �_�l�Ix y ��������e
	SDL_Rect blockRect_;
};

#endif //SPRITE_H
