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
	back = new Tile("background.png", 0, 0, 960, 720);
	back->setPos(0, 0);
	/*
	for (int i = 0;i < 50;i++)
	{
		Tile* grass = new Tile("map.png", 0, 0, 32, 32);
		grass->setPos(i * 32, 504-32);
		this->map.push_back(grass);
	}*/

	for (int i = 0;i < 1;i++)
	{
		Tile* grass = new Tile("map.png", 0, 32, 32, 32);
		grass->setPos(i * 32, 504 - 32 - 32-32);
		this->map.push_back(grass);
	}
	for (int i = 0;i < 4;i++)
	{
		Tile* grass = new Tile("map.png", 0, 32, 32, 32);
		grass->setPos(i * 32, 504-32-32);
		this->map.push_back(grass);
	}

	for (int i = 0;i < 6;i++)
	{
		Tile* grass = new Tile("map.png", 0, 32, 32, 32);
		grass->setPos(i * 32, 504-32);
		this->map.push_back(grass);
	}

	for (int i = 0;i < 20;i++)
	{
		Tile* grass = new Tile("map.png", 0, 32, 32, 32);
		grass->setPos( i * 32,504);
		this->map.push_back(grass);
	}

	for (int i = 0;i < 20;i++)
	{
		Tile* grass = new Tile("map.png", 0, 64, 32, 32);
		grass->setPos(i * 32, 504 + 32 * 1);
		this->map.push_back(grass);
	}



	for (int i = 0;i < 20;i++)
		for (int j = 2;j < 5;j++)
		{
			Tile* grass = new Tile("map.png", 0, 96, 32, 32);
			grass->setPos(i * 32, 504+32*j);
			this->map.push_back(grass);
		}
	

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
	shalof.checkCollision(map);
	shalof.update();

	return 1;
}

bool Title::Draw(SDL_Renderer* windowRenderer)
{
	back->draw();
	shalof.draw();
	for (int i = 0;i < map.size();i++)
	{
		map[i]->draw();
	}

	return 1;
}
