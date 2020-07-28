#include "M_ObjCharacter.h"
#include "Character.h"

Shalof::Shalof()
{
	posX = 800 / 2;
	posY = 600 / 2;
	spriiteHeight = 120;
	spriiteWidth = 80;
	imageFrame = 0;


	stateMachine[IDLE] = new IdleState(this);
	stateMachine[WALK] = new WalkState(this);
}
Shalof::~Shalof(){}

int Shalof::loadImage(char* path)
{
	image.loadFromFile(path);
	return 1;
}

int Shalof::draw()
{
	SDL_Rect clip = { 80 * imageFrame, this->state * 120, 80, 120 };

	if (this->direction == LEFT)
		image.render(this->posX, this->posY, &clip, SDL_FLIP_NONE);
	if (this->direction == RIGHT)
		image.render(this->posX, this->posY, &clip, SDL_FLIP_HORIZONTAL);
	return 1;
}


void Shalof::control(SDL_Event* e)
{
	stateMachine[state]->enter(e);
}


bool Shalof::update(double deltaT)
{
	

	posX += velX;
	posY += velY;


	changeTime += deltaT;
	if (changeTime >= stateMachine[state]->getImageTime(imageFrame))
	{
		changeTime -= stateMachine[state]->getImageTime(imageFrame);
		imageFrame += 1;
		//printf("%d1111000\n", imageFrame);
		if(imageFrame >= stateMachine[state]->getImageFrameNum())
		{
			imageFrame -= stateMachine[state]->getImageFrameNum();
			//printf("%d000000000\n", imageFrame);
		}
	}
	return 1;
}









IdleState::IdleState(Character *controlChar)
{
	this->controlChar = controlChar;
}

void IdleState::start()
{
	controlChar->imageFrame = 0;
	controlChar->changeTime = 0;
}

void IdleState::enter(SDL_Event* e)
{
	//If a key was pressed
	if (e->type == SDL_KEYDOWN && e->key.repeat == 0)
	{
		//Adjust the velocity
		switch (e->key.keysym.sym)
		{
		//case SDLK_UP: controlChar->velY -= 1; break;
		//case SDLK_DOWN: controlChar->velY += 1; break;
		case SDLK_LEFT:
		{
			controlChar->state = WALK;
			controlChar->direction = LEFT;
			controlChar->stateMachine[WALK]->start();
			//controlChar->velX -= 1;
			break;
		}
		case SDLK_RIGHT:
		{
			controlChar->state = WALK;
			controlChar->direction = RIGHT;
			controlChar->stateMachine[WALK]->start();
			//controlChar->velX += 1;
			break;
		}
		}
	}
}


int IdleState::getImageTime(int frameNum)
{
	return this->imageTime[frameNum];
}
int IdleState::getImageFrameNum()
{
	return this->imageFrameNum;
}


WalkState::WalkState(Character *controlChar)
{
	this->controlChar = controlChar;
}



void WalkState::start()
{
	controlChar->imageFrame = 0;
	controlChar->changeTime = 0;
	if (controlChar->direction == LEFT)
	{
		controlChar->velX -= 3;
	}
	else if (controlChar->direction == RIGHT)
	{
		controlChar->velX += 3;
	}
}

void WalkState::enter(SDL_Event* e)
{
	//If a key was released
	if (e->type == SDL_KEYUP && e->key.repeat == 0)
	{
	//Adjust the velocity
		switch (e->key.keysym.sym)
		{
			case SDLK_LEFT:
			{
				controlChar->state = IDLE;
				controlChar->velX += 3;
				controlChar->stateMachine[IDLE]->start();
				break;
			}
			case SDLK_RIGHT:
			{
				controlChar->state = IDLE;
				controlChar->velX -= 3;
				controlChar->stateMachine[IDLE]->start();
				break;
			}
		}
	}
}
int WalkState::getImageTime(int frameNum)
{
	return this->imageTime[frameNum];
}
int WalkState::getImageFrameNum()
{
	return this->imageFrameNum;
}