#include "Keyboard.h"

Keyboard::Keyboard()
{}

void Keyboard::handleEvent(SDL_KeyboardEvent &keyboardEvent, int triggeredTime)
{
	KeyData keydata;
	switch (keyboardEvent.type)
	{
	case SDL_KEYDOWN:
		keydata.type = SDL_KEYDOWN;
		keydata.releaseTime = triggeredTime;
		break;
	case SDL_KEYUP:
		keydata.type = SDL_KEYUP;
		keydata.pressTime = triggeredTime;
		break;
	}
	
	lastKey = keyboardEvent.keysym.sym;
	key[keyboardEvent.keysym.sym] = keydata;
}

SDL_EventType Keyboard::getKeyType(SDL_Keycode keyCode)
{
	return key[keyCode].type;
}

int Keyboard::getKeyClickDelta(SDL_Keycode keyCode)
{
	if (key[keyCode].releaseTime > key[keyCode].pressTime)
		return 0;
	else
		return key[keyCode].pressTime - key[keyCode].releaseTime;
}
