#include "Config.h"

#include "SDL.h"

int Config::SCREEN_FPS = 60;
int Config::SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
int Config::LOGIC_FPS = 60;
int Config::LOGIC_TICKS_PER_FRAME = 1000 / LOGIC_FPS;

int Config::SCREEN_WIDTH = 800;
int Config::SCREEN_HEIGHT = 600;
int Config::keyIdUp = SDLK_UP;
int Config::keyIdDown = SDLK_DOWN;
int Config::keyIdLeft = SDLK_LEFT;
int Config::keyIdRight = SDLK_RIGHT;



int Camera::cameraX;
int Camera::cameraY;
void Camera::setPlayerPos(int x, int y)
{
}

void Camera::update(int x, int y)
{
	Camera::cameraX = (x + 40 / 2) - Config::SCREEN_WIDTH / 2;
	Camera::cameraY = (y + 120 / 2) - (Config::SCREEN_HEIGHT+200) / 2;

	if (cameraX < 0)
	{
		cameraX = 0;
	}
	if (cameraY < 0)
	{
		cameraY = 0;
	}
	/*
	if (camera.x > LEVEL_WIDTH - camera.w)
	{
		camera.x = LEVEL_WIDTH - camera.w;
	}
	if (camera.y > LEVEL_HEIGHT - camera.h)
	{
		camera.y = LEVEL_HEIGHT - camera.h;
	}*/


}
