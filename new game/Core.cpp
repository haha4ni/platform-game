#include "Core.h"

//C include
#include <stdio.h>

//project include
#include "Config.h"
#include "Graphics.h"
#include "Timer.h"
#include "SceneState.h"

Core::Core()
{}

Core::~Core()
{}

bool Core::init(void)
{
	if (initSDL_() == 0)
		return false;
	if (initCore_() == 0)
		return false;
	return true;
}

bool Core::loop()
{
	timer->start();
	while (!quit) {
		int timeDalta = timer->getDalta();

		//更新數據
		if (timeDalta >= Config::LOGIC_TICKS_PER_FRAME)
		{
			timer->clearDalta();
			while (timeDalta >= Config::LOGIC_TICKS_PER_FRAME)
			{
				timeDalta -= Config::LOGIC_TICKS_PER_FRAME;
				this->input_();
				this->update_();
			}

			//邏輯幀綁顯示幀
			this->draw_();
		}
	}
	return 1;
}

bool Core::initSDL_()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	SDL_Joystick* gGameController = SDL_JoystickOpen(0);
	if (gGameController == NULL)
	{
		printf("Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
	}

	return true;
}

bool Core::initCore_()
{
	//TODO 物件剩一個 都改成靜態
	graphics = new Graphics;
	Graphics::init();

	timer = new TimerManager();
	keyboard = new Keyboard();

	sceneState = new Title;
	
	return 1;
}


void Core::input_()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
		//keyboard->handleEvent(event.key, timer->getTicks());

		if (event.type == SDL_QUIT)
			this->quit = true;
		else if (event.key.keysym.sym == SDLK_ESCAPE)
			this->quit = true;
			
		
		sceneState->Input(&event);
	}
}

void Core::update_()
{
	sceneState->Update();
}

void Core::draw_()
{
	//SDL_Delay(Config::SCREEN_TICKS_PER_FRAME - (timer->getTicks() - currentTime));//借放 沒用倒

	SDL_SetRenderDrawColor(Graphics::getRenderer(), 193, 238, 255, 0xFF);
	SDL_RenderClear(Graphics::getRenderer());
	sceneState->Draw(Graphics::getRenderer());

	//Update screen
	SDL_RenderPresent(Graphics::getRenderer());

	//printf("\nFPS : %lf", timer->updataFps());
}