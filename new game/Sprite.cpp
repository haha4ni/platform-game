#include "Sprite.h"

Graphics* Sprite::graphics_ = NULL;

Sprite::Sprite(){}
Sprite::~Sprite(){}

Sprite::Sprite(const std::string &filePath, int blockX, int blockY, int blockWidth, int blockHeight)
{
	SDL_Surface* imgSurface = Sprite::graphics_->loadImage(filePath);
	this->spriteSheet_ = SDL_CreateTextureFromSurface(Sprite::graphics_->getRenderer(), imgSurface);
	if (this->spriteSheet_ == NULL)
		printf("圖片載入失敗\n");

	this->blockRect_.x = blockX;
	this->blockRect_.y = blockY;
	this->blockRect_.w = blockWidth;
	this->blockRect_.h = blockHeight;
}

bool Sprite::setGraphics(Graphics* graphics)
{
	Sprite::graphics_ = graphics;
	return true;
}


void Sprite::update()
{
	//碰撞部分?

}

void Sprite::draw(int x, int y, SDL_RendererFlip flip)
{
	this->graphics_->render(this->spriteSheet_, x, y, &this->blockRect_, flip);
}