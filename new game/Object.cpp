#include "Object.h"

using namespace std;

Object::Object(){}
Object::~Object(){}

void Object::setupAnimation()
{
}

void Object::checkCollision(std::vector<Tile*> map)
{

	if (this->motionData_->velY <= 10.0)
	{
		this->motionData_->velY += 1;
	}

	this->motionData_->posX += this->motionData_->velX;
	this->motionData_->posY += this->motionData_->velY;


	for (int i = 0;i < map.size();i++)
	{
		CollisionBox temp = map[i]->getCollisionBox();

		if ((this->motionData_->posX + this->collisionBox_->posX) < temp.posX+temp.weight)
			if ((this->motionData_->posX + this->collisionBox_->posX + this->collisionBox_->weight) > temp.posX)
				if ((this->motionData_->posY + this->collisionBox_->posY) < temp.posY + temp.height)
					if ((this->motionData_->posY + this->collisionBox_->posY + this->collisionBox_->height) > temp.posY)

					if ((this->motionData_->posY + this->collisionBox_->posY + this->collisionBox_->height) < temp.posY + temp.height)

						
						{
							this->motionData_->velY = 0;
							this->motionData_->posY = temp.posY- this->collisionBox_->posY - this->collisionBox_->height;
						}
		

		if ((this->motionData_->posY + this->collisionBox_->posY) < temp.posY + temp.height)
			if ((this->motionData_->posY + this->collisionBox_->posY + this->collisionBox_->height) > temp.posY)
				if ((this->motionData_->posX + this->collisionBox_->posX) > temp.posX)
					if ((this->motionData_->posX + this->collisionBox_->posX) < temp.posX+temp.weight)
					{
						this->motionData_->velX = 0;
						this->motionData_->posX = temp.posX + temp.weight - this->collisionBox_->posX;
					}

		if ((this->motionData_->posY + this->collisionBox_->posY) < temp.posY + temp.height)
			if ((this->motionData_->posY + this->collisionBox_->posY + this->collisionBox_->height) > temp.posY)
				if ((this->motionData_->posX + this->collisionBox_->posX + this->collisionBox_->weight) > temp.posX)
					if ((this->motionData_->posX + this->collisionBox_->posX + this->collisionBox_->weight) < temp.posX + temp.weight)
					{
						this->motionData_->velX = 0;
						this->motionData_->posX = temp.posX - this->collisionBox_->posX - this->collisionBox_->weight;//TODO
					}

	}



	if (this->motionData_->posY >= 400)
	{

	}
}


void Object::changeAnimation(string action)
{
	this->sprite_->changeAnimation(action);
}


void Object::update()
{
	this->sprite_->update();
	this->stateMachine_->update();



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
	this->collisionBox_ = new CollisionBox{ 0,0,32,32 };
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

CollisionBox Tile::getCollisionBox()
{
	return CollisionBox{ posX_ , posY_ ,32 ,32};
}
