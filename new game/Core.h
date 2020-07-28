#ifndef CORE_H
#define CORE_H

// SDL include
#include <SDL.h>
#include <SDL_image.h>

// Project include
#include "Graphics.h"
#include "Timer.h"
#include "Keyboard.h"
#include "SceneState.h"


class Core
{
public:
	Core();
	~Core();

	bool init(void);
	bool loop(void);

private:
	bool quit = false;
	
	// Initialization function
	bool initSDL_();
	bool initCore_();

	// Loop function
	void input_();
	void update_();
	void draw_();

	// Components
	Graphics* graphics;
	TimerManager* timer;
	Keyboard* keyboard;

	SceneState* sceneState;
};

#endif // CORE_H