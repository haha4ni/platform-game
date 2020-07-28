#ifndef _SCENE_H
#define _SCENE_H


//SDL include
#include <SDL.h>
#include "Object.h"
#include "Player.h"

class SceneState
{
public:
	SceneState();
	~SceneState();

	virtual bool Input(SDL_Event* e);
	virtual bool Update();
	virtual bool Draw(SDL_Renderer* windowRenderer);
private:

};



class Title : public SceneState
{
public:
	Title();
	~Title();

	bool Input(SDL_Event* e);
	bool Update();
	bool Draw(SDL_Renderer* windowRenderer);
private:
	int loading = 0;

	Player shalof;
};


#endif