#ifndef _TIMER_H
#define _TIMER_H

//C/C++ include
#include <stdio.h>
#include <queue>
using namespace std;

//SDL include
#include <SDL.h>

//TODO : 重複太高 重寫

//The application time based timer
class Timer
{
public:
	//Initializes variables
	Timer();

	//The various clock actions
	void start();
	void stop();
	//void pause();
	//void unpause();
	void offset(int microTime);

	//Gets the timer's time
	Uint32 getTicks();

	//Checks the status of the timer
	//bool isStarted();
	//bool isPaused();

private:
	//The clock time when the timer started
	Uint32 mStartTicks;

	//The ticks stored when the timer was paused
	Uint32 mPausedTicks;

	//The timer status
	bool paused;
	bool started;
};

class TimerManager
{
public:
	TimerManager();
	void start();
	int getDalta();
	void clearDalta();
	double updataFps();

	int getTicks();
private:
	Timer timer;
	Uint32 currentTime;
	Uint32 nextSubtractTime;
	Uint32 accUpdataTime;

	//fps
	queue<int> frameTimeQueue;
	int startTick = 0;
	double fps = 0;
};

#endif