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
	int posX = 150, posY = 0;
	int velX = 0, velY = 0;//Velocity
	//int prevWalkTimeL, prevWalkTimeR;
};

class Object
{
public:
	Object();
	~Object();
	void setupAnimation();
	

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
};

#endif // !CHARACTER_H


