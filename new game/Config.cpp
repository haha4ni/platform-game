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