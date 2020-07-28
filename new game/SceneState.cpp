#include "SceneState.h"

SceneState::SceneState()
{}
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
{}
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

	return 1;
}
