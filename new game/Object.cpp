#include "Object.h"

using namespace std;

Object::Object(){}
Object::~Object(){}

void Object::setupAnimation()
{
}

void Object::changeAnimation(string action)
{
	this->sprite_->changeAnimation(action);
}

void Object::update()
{
	this->sprite_->update();
	this->stateMachine_->update();


	if (this->motionData_->velY <= 10.0)
	{
		this->motionData_->velY += 1;
	}

	this->motionData_->posX += this->motionData_->velX;
	this->motionData_->posY += this->motionData_->velY;


	if (this->motionData_->posY >= 400)
	{
		this->motionData_->velY = 0;
		this->motionData_->posY = 400;
	}
}

void Object::draw()
{
	if(this->motionData_->direction == MotionData::Direction::RIGHT)
		this->sprite_->draw(this->motionData_->posX, this->motionData_->posY, SDL_FLIP_HORIZONTAL);
	else
		this->sprite_->draw(this->motionData_->posX, this->motionData_->posY, SDL_FLIP_NONE);
}

void Object::setStateMachine(StateMachine* stateMachine)
{
	delete this->stateMachine_;
	this->stateMachine_ = stateMachine;
	this->stateMachine_->setup();
}




Tile::Tile(string file_name, int blockX, int blockY, int blockWidth, int blockHeight)
{
	this->sprite_ = new Sprite(file_name, blockX, blockY, blockWidth, blockHeight);
}
Tile::~Tile()
{

}
void Tile::setPos(int posX, int posY)
{
	posX_ = posX;
	posY_ = posY;
}
void Tile::update()
{

}
void Tile::draw()
{
	this->sprite_->draw(posX_, posY_, SDL_FLIP_NONE);
}