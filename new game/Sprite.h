#ifndef SPRITE_H
#define SPRITE_H

#include "Graphics.h"

class Sprite
{
public:
	Sprite();
	Sprite::Sprite(const std::string &filePath, int blockX, int blockY, int blockWidth, int blockHeight);
	~Sprite();

	static bool setGraphics(Graphics* graphics);

	virtual void update();
	virtual void draw(int x, int y, SDL_RendererFlip flip);

protected:
	static Graphics* graphics_;
	//���J������
	SDL_Texture* spriteSheet_;
	//block�y�� �_�l�Ix y ��������e
	SDL_Rect blockRect_;
};

#endif //SPRITE_H
