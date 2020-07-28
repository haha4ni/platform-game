#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "Controller.h"
class Object;
class AnimatedSprite;
class MotionData;

class StateMachine
{
public:
	StateMachine(Object* Object, MotionData* motionData);
	virtual void setup() = 0;
	virtual void input(ControlKey key) = 0;
	virtual void update() = 0;
protected:
	Object* Object_;
	MotionData* motionData_;
};

class ActiveStateMachine : public StateMachine
{
public:
	ActiveStateMachine(Object* Object, MotionData* motionData);
	virtual void input(ControlKey key) = 0;
};

namespace Shalof
{
	class IdleState : public ActiveStateMachine
	{
	public:
		IdleState(Object* Object, MotionData* motionData);
		void setup();
		void input(ControlKey key);
		void update();
	};


	class WalkState : public ActiveStateMachine
	{
	public:
		WalkState(Object* Object, MotionData* motionData);
		void setup();
		void input(ControlKey key);
		void update();
	};

	class JumpState : public ActiveStateMachine
	{
	public:
		JumpState(Object* Object, MotionData* motionData);
		void setup();
		void input(ControlKey key);
		void update();
	};
	
	class FallState : public ActiveStateMachine
	{
	public:
		FallState(Object* Object, MotionData* motionData);
		void setup();
		void input(ControlKey key);
		void update();
	};
}

#endif //STATE_MACHINE_H