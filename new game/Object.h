#ifndef CHARACTER_H
#define CHARACTER_H

#include "AnimatedSprite.h"
#include "Controller.h"
#include "StateMachine.h"


/*
class GravityFactor
{
public:
	GravityFactor(Object* object, MotionData* motionData)
	{
		object_ = object;
		motionData_ = motionData;
	}
	~GravityFactor()
	{
	}

	void update()
	{
	}
protected:
	Object* object_;
	MotionData* motionData_;
};*/

struct MotionData
{
	enum Direction
	{
		LEFT = 0,
		RIGHT,
	};

	Direction direction = RIGHT;
	int posX = 200, posY = 0;
	int velX = 0, velY = 0;//Velocity
	//int prevWalkTimeL, prevWalkTimeR;
};

struct CollisionBox
{
	int posX = 0, posY = 0;
	int weight = 0, height = 0;
};







class Tile
{
public:
	Tile(std::string file_name, int blockX, int blockY, int blockWidth, int blockHeight);
	~Tile();

	void setPos(int posX, int poxY);
	void update();
	void draw();

	CollisionBox getCollisionBox();

protected:
	Sprite* sprite_;
	int posX_=0, posY_=0;

	CollisionBox* collisionBox_;
};




class Object
{
public:
	Object();
	~Object();
	void setupAnimation();

	virtual void checkCollision(std::vector<Tile*> map);
	//virtual void checkCollision(std::vector<Object*> object);
	virtual void update();
	virtual void draw();

	//----------------------
	virtual void setStateMachine(StateMachine* stateMachine);
	void changeAnimation(std::string action);
protected:
	//GravityFactor* gravityFactor_;
	StateMachine* stateMachine_;

	AnimatedSprite* sprite_;
	MotionData* motionData_;
	CollisionBox* collisionBox_;
};







#endif // !CHARACTER_H


