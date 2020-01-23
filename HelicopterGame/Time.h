#pragma once

#include <chrono>

class Time {
public:
	bool Init();
	void Cleanup();
	void Update();
	float GetDeltaTime();

private:
	std::chrono::high_resolution_clock::time_point _lastFrameTimePoint = std::chrono::high_resolution_clock::now();
	float _deltaTime;
};