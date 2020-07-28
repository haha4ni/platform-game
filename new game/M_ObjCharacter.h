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

	/*動作總數*/
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
	/*動作狀態機*/
	State *stateMachine[ACTION_NUM];
	Action state;
	int direction;

	int posX, posY;
	//Velocity
	int velX, velY;

	

	/* 圖片相關 */
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







/*創建*/
class Shalof : public Character
{
public:
	Shalof();
	~Shalof();

	//玩家控制輸入
	void control(SDL_Event* e);

	//邏輯更新
	bool update(double deltaT);

	int loadImage(char* path);
	int draw();
};

#endif