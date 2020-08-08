#include "Sprite.h"

Sprite::Sprite(){}
Sprite::~Sprite(){}

Sprite::Sprite(const std::string &filePath, int blockX, int blockY, int blockWidth, int blockHeight)
{
	SDL_Surface* imgSurface = Graphics::loadImage(filePath);
	this->spriteSheet_ = SDL_CreateTextureFromSurface(Graphics::getRenderer(), imgSurface);
	if (this->spriteSheet_ == NULL)
		printf("圖片載入失敗\n");

	this->blockRect_.x = blockX;
	this->blockRect_.y = blockY;
	this->blockRect_.w = blockWidth;
	this->blockRect_.h = blockHeight;
}


void Sprite::update()
{
	//碰撞部分?

}

void Sprite::draw(int x, int y, SDL_RendererFlip flip)
{
	// 這邊依據不同的底層做替換就好
	Graphics::render(this->spriteSheet_, x, y, &this->blockRect_, flip);
}