#include "stdafx.h"
#include "Timer.h"

void Timer::Init(__int64 milli, TimerLambda func)
{
	isRunning = false;
	initialTime = leftTime = milli;

	this->func = func;
}

void Timer::Start()
{
	isRunning = true;
	now = std::chrono::steady_clock::now();
}

bool Timer::Update()
{
	if (isRunning == false)
	{
		return false;
	}

	auto newNow = std::chrono::steady_clock::now();
	auto diff = now - newNow;
	now = newNow;

	auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
	leftTime -= milli;

	if (leftTime <= 0)
	{
		Stop();

		func();

		return true;
	}
	else
	{
		return false;
	}
}

void Timer::Pause()
{
	isRunning = false;
}

void Timer::Resume()
{
	isRunning = true;
}

void Timer::Stop()
{
	isRunning = false;
	leftTime = initialTime;
}