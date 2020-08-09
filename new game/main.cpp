/*
 *  New game! by yaomei65
 */

//Display console
#pragma comment(linker, "/subsystem:console /entry:WinMainCRTStartup")
//"/subsystem:console /entry:WinMainCRTStartup"

//C include
#include <stdio.h>
#include <stdlib.h>

//Core include
#include "Core.h"

int main(int argc, char** argv)
{
	Core core;
	core.init();
	core.loop();

	return 0;
}


