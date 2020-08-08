#include "SceneState.h"

SceneState::SceneState()
{
}
SceneState::~SceneState()
{}
bool SceneState::Input(SDL_Event* e)
{
	return 0;
}
bool SceneState::Update()
{
	return 0;
}
bool SceneState::Draw(SDL_Renderer* windowRenderer)
{
	return 0;
}

Title::Title()
{
	Sprite* grass = new Sprite("map.png", 0, 0, 32, 32);
	this->map.push_back(grass);

}
Title::~Title()
{}

bool Title::Input(SDL_Event* e)
{
	shalof.controller_->transControl(*e);

	return 1;
}

bool Title::Update()
{
	shalof.update();

	return 1;
}

bool Title::Draw(SDL_Renderer* windowRenderer)
{
	shalof.draw();
	for (int i = 0;i < map.size();i++)
	{
		//map[i]->draw();
	}

	return 1;
}
