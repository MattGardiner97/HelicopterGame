#pragma once
#include "Difficulty.h"

class EasyDifficulty : public Difficulty {
public:
	std::string GetDifficultyName();
	int GetObstacleSpacing();
	int GetObstacleGapHeight();
	int GetObstacleMaxShift();
	int GetHelicopterHorizontalVelocity();


private:
	const std::string DIFFICULTY_STRING = "Easy";
	const int OBSTACLE_SPACING = 200;
	const int OBSTACLE_GAP_HEIGHT = 140;
	const int OBSTACLE_MAX_SHIFT = 90;
	const int HELICOPTER_HORIZONTAL_VELOCITY = 100;

};
