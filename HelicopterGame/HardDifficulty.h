#pragma once
#include "Difficulty.h"

class HardDifficulty : public Difficulty {
public:
	std::string GetDifficultyName();
	int GetObstacleSpacing();
	int GetObstacleGapHeight();
	int GetObstacleMaxShift();
	int GetHelicopterHorizontalVelocity();


private:
	const std::string DIFFICULTY_STRING = "Hard";
	const int OBSTACLE_SPACING = 150;
	const int OBSTACLE_GAP_HEIGHT = 90;
	const int OBSTACLE_MAX_SHIFT = 130;
	const int HELICOPTER_HORIZONTAL_VELOCITY = 150;

};
