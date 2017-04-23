#pragma once

#include <functional>
#include <chrono>

class Timer
{
public:
	using TimerLambda = std::function<void(void)>;

	void Init(__int64 milli, TimerLambda func);

	void Start();
	bool Update();

	void Pause();
	void Resume();
	void Stop();

private:
	bool isRunning = false;
	__int64 initialTime = 0;
	__int64 leftTime = 0;

	TimerLambda func = nullptr;

	std::chrono::steady_clock::time_point now;
};