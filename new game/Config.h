#ifndef _CONFIG_H
#define _CONFIG_H

class Config
{
public:
	static int SCREEN_FPS; 
	static int SCREEN_TICKS_PER_FRAME;

	static int LOGIC_FPS;
	static int LOGIC_TICKS_PER_FRAME;

	static int SCREEN_WIDTH, SCREEN_HEIGHT;
	static int keyIdUp, keyIdDown, keyIdLeft, keyIdRight;
};


#endif