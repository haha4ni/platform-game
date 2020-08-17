#include "Sprite.h"


Sprite::Sprite()
{
}

Sprite::Sprite(const std::string &filePath, int blockX, int blockY, int blockWidth, int blockHeight)
{
	this->spriteSheet_ = Graphics::loadImage(filePath);
	if (this->spriteSheet_ == NULL)
		printf("�Ϥ����J����\n");

	this->blockRect_.x = blockX;
	this->blockRect_.y = blockY;
	this->blockRect_.w = blockWidth;
	this->blockRect_.h = blockHeight;
}


void Sprite::loadImage(const std::string& filePath, int blockX, int blockY, int blockWidth, int blockHeight)
{
	this->spriteSheet_ = Graphics::loadImage(filePath);
	if (this->spriteSheet_ == NULL)
		printf("�Ϥ����J����\n");

	this->blockRect_.x = blockX;
	this->blockRect_.y = blockY;
	this->blockRect_.w = blockWidth;
	this->blockRect_.h = blockHeight;
}

void Sprite::update()
{
}

void Sprite::draw(int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE)
{
	// �o��̾ڤ��P�����h�������N�n
	Graphics::render(this->spriteSheet_, x, y, &this->blockRect_, flip);
}