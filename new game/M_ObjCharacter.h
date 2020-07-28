#ifndef _CHAR_H
#define _CHAR_H


#include "Graphics.h"
#include "TimerManager.h"


enum Action
{
	IDLE = 0,
	WALK,
	RUN,
	JUMP,

	/*�ʧ@�`��*/
	ACTION_NUM
};

enum Direction
{
	LEFT = 0,
	RIGHT,
};


class State
{
public:
	virtual void start() = 0;
	virtual void enter(SDL_Event* e) = 0;
	virtual int getImageTime(int frameNum) = 0;
	virtual int getImageFrameNum() = 0;
};

class Character
{
public:
	virtual bool update(double deltaT) = 0;
	virtual int loadImage(char* path) = 0;
	virtual int draw() = 0;

	//int setState(State *intputState);
	//int getDirection();
//protected:
	/*�ʧ@���A��*/
	State *stateMachine[ACTION_NUM];
	Action state;
	int direction;

	int posX, posY;
	//Velocity
	int velX, velY;

	

	/* �Ϥ����� */
	Graphics image;
	int spriiteHeight, spriiteWidth;
	int changeTime = 0;
	int imageFrame;
};


class IdleState : public State
{
private:
	Character *controlChar;
	int imageTime[8] = { 160, 160, 160, 160, 160, 160, 160, 160 };
	int imageFrameNum = 8;
	int delayTime = 0;
public:
	IdleState(Character *controlChar);
	void start();
	void enter(SDL_Event* e);
	int getImageTime(int frameNum);
	int getImageFrameNum();
};


class WalkState : public State
{
private:
	Character *controlChar;
	int imageTime[8] = { 160,160, 160, 160, 160, 160, 160, 160 };
	int imageFrameNum = 8;
	int delayTime = 0;
public:
	WalkState(Character *controlChar);
	void start();
	void enter(SDL_Event* e);
	int getImageTime(int frameNum);
	int getImageFrameNum();
};

/*
class RunState : public State
{
private:
	Character *controlChar;
public:
	RunState(Character *controlChar);
	void enter(SDL_Event* e);
	Action getState();
};
*/







/*�Ы�*/
class Shalof : public Character
{
public:
	Shalof();
	~Shalof();

	//���a�����J
	void control(SDL_Event* e);

	//�޿��s
	bool update(double deltaT);

	int loadImage(char* path);
	int draw();
};

#endif