#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"
class Controller;

class Player : public Object
{
public:
	Player();
	~Player();

	void update();
	void setStateMachine(StateMachine* stateMachine);
	Controller* controller_;
};

#endif //PLAYER_H
