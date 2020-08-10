#include "StateMachine.h"
#include "Object.h"

StateMachine::StateMachine(Object* Object, MotionData* motionData)
{
	this->Object_ = Object;
	this->motionData_ = motionData;
}

ActiveStateMachine::ActiveStateMachine(Object* Object, MotionData* motionData)
	: StateMachine(Object, motionData)
{
}

namespace Shalof
{
	IdleState::IdleState(Object* Object, MotionData* motionData)
		: ActiveStateMachine(Object, motionData)
	{
	}
	void IdleState::setup()
	{
		this->Object_->changeAnimation("idle");
		this->motionData_->velX = 0;
		this->motionData_->velY = 0;+
		printf("\nIdle");
	}
	void IdleState::update()
	{
		if (this->motionData_->velY > 0)
			this->Object_->setStateMachine(new Shalof::FallState(this->Object_, this->motionData_));
	}
	void IdleState::input(ControlKey key)
	{
		//If a key was pressed
		if (key.log[key.curr].type == KeyType::PRESSED)
		{
			//Adjust the velocity
			switch (key.curr)
			{
				case KeyCode::LEFT:
				{
					this->motionData_->direction = MotionData::Direction::LEFT;
					this->Object_->setStateMachine(new Shalof::WalkState(this->Object_, this->motionData_));
					break;
				}
				case KeyCode::RIGHT:
				{
					this->motionData_->direction = MotionData::Direction::RIGHT;
					this->Object_->setStateMachine(new Shalof::WalkState(this->Object_, this->motionData_));
					break;
				}
				case KeyCode::CROSS:
				{
					this->Object_->setStateMachine(new Shalof::JumpState(this->Object_, this->motionData_));
					break;
				}
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	WalkState::WalkState(Object* Object, MotionData* motionData)
		: ActiveStateMachine(Object, motionData)
	{
	}
	void WalkState::setup()
	{
		printf("\nRun");
		this->Object_->changeAnimation("run");
		if (this->motionData_->direction == MotionData::Direction::LEFT)
		{
			this->motionData_->velX = -3;
		}
		else if (this->motionData_->direction == MotionData::Direction::RIGHT)
		{
			this->motionData_->velX = 3;
		}
	}
	void WalkState::input(ControlKey key)
	{
		//If a key was pressed
		if (key.log[key.curr].type == KeyType::PRESSED)
		{
			switch (key.curr)
			{
			case KeyCode::LEFT:
			{
				this->motionData_->direction = MotionData::Direction::LEFT;
				this->motionData_->velX = -3;
				break;
			}
			case KeyCode::RIGHT:
			{
				this->motionData_->direction = MotionData::Direction::RIGHT;
				this->motionData_->velX = 3;
				break;
			}
			case KeyCode::CROSS:
			{
				if(this->motionData_->velY == 0)
				this->Object_->setStateMachine(new Shalof::JumpState(this->Object_, this->motionData_));
				break;
			}
			}
		}
		else
		{
			if (key.log[KeyCode::LEFT].type == KeyType::RELEASED &&
				key.log[KeyCode::RIGHT].type == KeyType::RELEASED)
			{
				this->Object_->setStateMachine(new Shalof::IdleState(this->Object_, this->motionData_));
				return;
			}
			else if (key.log[KeyCode::LEFT].type == KeyType::PRESSED)
			{
				this->motionData_->direction = MotionData::Direction::LEFT;
				this->motionData_->velX = -3;
			}
			else if (key.log[KeyCode::RIGHT].type == KeyType::PRESSED)
			{
				this->motionData_->direction = MotionData::Direction::RIGHT;
				this->motionData_->velX = 3;
			}
		}

	}
	void WalkState::update()
	{

	}

	////////////
	JumpState::JumpState(Object* Object, MotionData* motionData)
		: ActiveStateMachine(Object, motionData)
	{

	}
	void JumpState::setup()
	{
		printf("\nJump");
		this->Object_->changeAnimation("jump");
		//this->motionData_->velX = 0;
		this->motionData_->velY = -10;
	}
	void JumpState::input(ControlKey key)
	{
		//If a key was pressed
		if (key.log[key.curr].type == KeyType::PRESSED)
		{
			switch (key.curr)
			{
			case KeyCode::LEFT:
			{
				this->motionData_->direction = MotionData::Direction::LEFT;
				this->motionData_->velX = -3;
				break;
			}
			case KeyCode::RIGHT:
			{
				this->motionData_->direction = MotionData::Direction::RIGHT;
				this->motionData_->velX = 3;
				break;
			}
			}
		}
		else
		{
			if (key.log[KeyCode::LEFT].type == KeyType::RELEASED &&
				key.log[KeyCode::RIGHT].type == KeyType::RELEASED)
			{
				this->motionData_->velX = 0;
			}
			else if (key.log[KeyCode::LEFT].type == KeyType::PRESSED)
			{
				this->motionData_->direction = MotionData::Direction::LEFT;
				this->motionData_->velX = -3;
			}
			else if (key.log[KeyCode::RIGHT].type == KeyType::PRESSED)
			{
				this->motionData_->direction = MotionData::Direction::RIGHT;
				this->motionData_->velX = 3;
			}
		}
	}
	void JumpState::update()
	{
		if (this->motionData_->velY >= 0)
			this->Object_->setStateMachine(new Shalof::FallState(this->Object_, this->motionData_));

	}

	///////////////////////////////////////////////////////
	FallState::FallState(Object* Object, MotionData* motionData)
		: ActiveStateMachine(Object, motionData)
	{
	}
	void FallState::setup()
	{
		this->Object_->changeAnimation("fall");
		printf("\nFall");
	}
	void FallState::input(ControlKey key)
	{
		//If a key was pressed
		if (key.log[key.curr].type == KeyType::PRESSED)
		{
			switch (key.curr)
			{
			case KeyCode::LEFT:
			{
				this->motionData_->direction = MotionData::Direction::LEFT;
				this->motionData_->velX = -3;
				break;
			}
			case KeyCode::RIGHT:
			{
				this->motionData_->direction = MotionData::Direction::RIGHT;
				this->motionData_->velX = 3;
				break;
			}
			}
		}
		else
		{
			if (key.log[KeyCode::LEFT].type == KeyType::RELEASED &&
				key.log[KeyCode::RIGHT].type == KeyType::RELEASED)
			{
				this->motionData_->velX = 0;
			}
			else if (key.log[KeyCode::LEFT].type == KeyType::PRESSED)
			{
				this->motionData_->direction = MotionData::Direction::LEFT;
				this->motionData_->velX = -3;
			}
			else if (key.log[KeyCode::RIGHT].type == KeyType::PRESSED)
			{
				this->motionData_->direction = MotionData::Direction::RIGHT;
				this->motionData_->velX = 3;
			}
		}
	}
	void FallState::update()
	{
		if (this->motionData_->velY <= 0)
		{
			if (this->motionData_->velX != 0)
				this->Object_->setStateMachine(new Shalof::WalkState(this->Object_, this->motionData_));
			else
				this->Object_->setStateMachine(new Shalof::IdleState(this->Object_, this->motionData_));
		}
			
	}
}
