#include "Graphics.h"

//C++ include
#include <string>
using namespace std;

//project include
#include "Config.h"


SDL_Window* Graphics::window = NULL;
SDL_Renderer* Graphics::renderer = NULL;
std::map<std::string, SDL_Surface*> Graphics::surface_list_;
std::map<std::string, SDL_Texture*> Graphics::texture_list_;

/*
Graphics::Graphics(){}
Graphics::~Graphics()
{
	SDL_FreeSurface( loadedSurface );//清除記憶體用
	SDL_DestroyTexture( texture );//清除記憶體用

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
*/

bool Graphics::init()
{
	Graphics::initWindow_();
	Graphics::initRenderer_();

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
	Graphics::window = SDL_CreateWindow("Platform", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (Graphics::window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return 0;
	}

	return Graphics::window;
}

SDL_Renderer* Graphics::initRenderer_()
{
	//Create renderer for window
	Graphics::renderer = SDL_CreateRenderer(Graphics::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Graphics::renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return 0;
	}
	//SDL_RenderSetScale(windowRenderer, 2, 2);//縮放倍率
	//background color
	SDL_SetRenderDrawColor(Graphics::renderer, 0x00, 0x00, 0x00, 0x00);

	return Graphics::renderer;
}

SDL_Window* Graphics::getWindow()
{
	return Graphics::window;
}
SDL_Renderer* Graphics::getRenderer()
{
	return Graphics::renderer;
}

SDL_Texture* Graphics::loadImage(const std::string &filePath)
{
	if (Graphics::surface_list_.count(filePath) == 0) {
		surface_list_[filePath] = IMG_Load(filePath.c_str());
		SDL_SetColorKey(surface_list_[filePath], SDL_TRUE, SDL_MapRGB(surface_list_[filePath]->format, 0x3A, 0xA7, 0x99));//透明色
	}
	if (Graphics::texture_list_.count(filePath) == 0) {
		texture_list_[filePath] = SDL_CreateTextureFromSurface(Graphics::getRenderer(), surface_list_[filePath]);
	}

	return Graphics::texture_list_[filePath];
}

void Graphics::freeOneImage(const std::string& filePath)
{
}

void Graphics::freeAllImage()
{
}

void Graphics::render(SDL_Texture* texture, int x, int y, SDL_Rect* block, SDL_RendererFlip rotate)
{
	//Set rendering space and render to screen
	//目標位置、拉伸寬高
	SDL_Rect renderQuad = { x- Camera::cameraX, y - Camera::cameraY, block->w, block->h };

	if (!rotate)
		SDL_RenderCopy(Graphics::renderer, texture, block, &renderQuad);
	else
		SDL_RenderCopyEx(Graphics::renderer, texture, block, &renderQuad, NULL, NULL, rotate);
}