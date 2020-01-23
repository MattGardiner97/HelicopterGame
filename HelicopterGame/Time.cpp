#include "Time.h"

bool Time::Init() {
	return true;
}

void Time::Cleanup() {
	return;
}

void  Time::Update() {
	std::chrono::high_resolution_clock::time_point currentTimePoint = std::chrono::high_resolution_clock::now();
	_deltaTime = (float)std::chrono::duration_cast<std::chrono::milliseconds>(currentTimePoint - _lastFrameTimePoint).count() / 1000;
	_lastFrameTimePoint = currentTimePoint;
}

float Time::GetDeltaTime() {
	return _deltaTime;
}