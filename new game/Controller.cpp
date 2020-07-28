#include "Controller.h"
#include "Player.h"

Controller::Controller(){}
Controller::~Controller(){}

Controller::Controller(ControlKeys controlKeys, StateMachine* stateMachine)
{
	this->controlKeys_ = controlKeys;
	this->stateMachine_ = stateMachine;
}

void Controller::transControl(SDL_Event &event)
{
	int tirggerFlag = 0;
	switch (event.type)
	{
	case SDL_JOYBUTTONDOWN:
		printf("event.type : %d", event.jbutton.which);
	case SDL_KEYDOWN:
		for (int codeId = 0; codeId < KeyCode::CODE_NUM; codeId++)
		{
			//只留下要的
			if (event.key.keysym.sym == this->controlKeys_.data[codeId])
			{
				this->controlKey_.curr = (KeyCode)codeId;
				this->controlKey_.log[this->controlKey_.curr].type = KeyType::PRESSED;
				tirggerFlag = 1;
				break;
			}
		}
		break;
	case SDL_JOYBUTTONUP:
	case SDL_KEYUP:
		for (int codeId = 0; codeId < KeyCode::CODE_NUM; codeId++)
		{
			if (event.key.keysym.sym == this->controlKeys_.data[codeId])
			{
				this->controlKey_.curr = (KeyCode)codeId;
				this->controlKey_.log[this->controlKey_.curr].type = KeyType::RELEASED;
				tirggerFlag = 1;
				break;
			}
		}
		break;
	}

	//有觸發才GO
	if (tirggerFlag == 1)
	{
		tirggerFlag = 0;
		this->stateMachine_->input(this->controlKey_);
	}
}

void Controller::setControlKeys(ControlKeys controlKeys)
{
	this->controlKeys_ = controlKeys;
}

ControlKeys Controller::getControlKeys()
{
	return this->controlKeys_;
}
