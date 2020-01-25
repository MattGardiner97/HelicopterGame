#pragma once

#include <string>

class Difficulty {
public: 
	virtual std::string GetDifficultyName() = 0;
	virtual int GetObstacleSpacing() = 0;
	virtual int GetObstacleGapHeight() = 0;
	virtual int GetObstacleMaxShift() = 0;
	virtual int GetHelicopterHorizontalVelocity() = 0;

private:
	std::string _difficultyName;
};