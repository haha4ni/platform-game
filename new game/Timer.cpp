#include "Timer.h"

Timer::Timer()
{
	//Initialize the variables
	mStartTicks = 0;
	mPausedTicks = 0;

	paused = false;
	started = false;
}

void Timer::start()
{
	//Start the timer
	started = true;

	//Unpause the timer
	paused = false;

	//Get the current clock time
	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void Timer::stop()
{
	//Stop the timer
	started = false;

	//Unpause the timer
	paused = false;

	//Clear tick variables
	mStartTicks = 0;
	mPausedTicks = 0;
}

Uint32 Timer::getTicks()
{
	//The actual timer time
	Uint32 time = 0;

	//If the timer is running
	if (started)
	{
		//If the timer is paused
		if (paused)
		{
			//Return the number of ticks when the timer was paused
			time = mPausedTicks;
		}
		else
		{
			//Return the current time minus the start time
			time = SDL_GetTicks() - mStartTicks;
		}
	}

	return time;
}

void Timer::offset(int microTime)
{
	mStartTicks += microTime;
}



TimerManager::TimerManager()
{

}
void TimerManager::start()
{
	timer.start();
	nextSubtractTime = timer.getTicks();
	startTick = timer.getTicks();
}
int TimerManager::getDalta()
{
	currentTime = timer.getTicks();
	Uint32 deltaTime = currentTime - nextSubtractTime;
	return deltaTime;
}

void TimerManager::clearDalta()
{
	nextSubtractTime = currentTime;
}

double TimerManager::updataFps()
{
	int endTick = timer.getTicks();
	if (frameTimeQueue.size() < 50) // 樣本張數
	{
		int interval = endTick - startTick;
		fps += interval;
		frameTimeQueue.push(interval);
	}
	else
	{
		fps -= frameTimeQueue.front();
		frameTimeQueue.pop();
		int interval = endTick - startTick;
		fps += interval;
		frameTimeQueue.push(interval);
	}
	startTick = endTick;

	return  static_cast<double>((frameTimeQueue.size())*1000.0 / fps);//FPS IS MAGIC
}

int TimerManager::getTicks()
{
	return timer.getTicks();
}
