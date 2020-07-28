#ifndef KEYBOARD_H
#define KEYBOARD_H

/* Keyboard class
 * ���s�B�z��L�A�l�[�I���ɶ�
 * ���ݩ�SDL������
 */

// C/C++ include
#include <map>

// SDL include
#include "SDL.h"

typedef struct KeyData
{
	SDL_EventType type = SDL_KEYUP;
	int pressTime = 0;
	int releaseTime = 0;
}KeyData;

class Keyboard
{
public:
	Keyboard::Keyboard();

	void handleEvent(SDL_KeyboardEvent &keyboardEvent, int triggeredTime);

	SDL_EventType getKeyType(SDL_Keycode keyCode);
	int getKeyClickDelta(SDL_Keycode keyCode);
private:
	SDL_Keycode lastKey;
	std::map<SDL_Keycode, KeyData> key;
};

#endif //KEY_BOARD_H