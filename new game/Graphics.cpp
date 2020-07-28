#include "Graphics.h"

//C++ include
#include <string>
using namespace std;

//project include
#include "Config.h"


Graphics::Graphics()
{}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

bool Graphics::init()
{
	this->initWindow_();
	this->initRenderer_();

	return 1;
}

SDL_Window* Graphics::initWindow_()
{
#if 0
	// 縮放平滑
	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		printf("Warning: Linear texture filtering not enabled!");
#endif
	//Create window
	this->window = SDL_CreateWindow("Platform", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (this->window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return 0;
	}

	return this->window;
}

SDL_Renderer* Graphics::initRenderer_()
{
	//Create renderer for window
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (this->renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return 0;
	}
	//SDL_RenderSetScale(windowRenderer, 2, 2);//縮放倍率
	//background color
	SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00);

	return this->renderer;
}

SDL_Window* Graphics::getWindow()
{
	return this->window;
}
SDL_Renderer* Graphics::getRenderer()
{
	return this->renderer;
}

SDL_Surface* Graphics::loadImage(const std::string &filePath)
{
	if (this->spriteSheets_.count(filePath) == 0) {
		spriteSheets_[filePath] = IMG_Load(filePath.c_str());
	}
	return this->spriteSheets_[filePath];
}

void Graphics::render(SDL_Texture* texture, int x, int y, SDL_Rect* block, SDL_RendererFlip rotate)
{
	//Set rendering space and render to screen
	//目標位置、拉伸寬高
	SDL_Rect renderQuad = { x, y, block->w, block->h };

	if (!rotate)
		SDL_RenderCopy(this->renderer, texture, block, &renderQuad);
	else
		SDL_RenderCopyEx(this->renderer, texture, block, &renderQuad, NULL, NULL, rotate);
}