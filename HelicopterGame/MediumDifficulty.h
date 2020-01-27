#pragma once
#include "Difficulty.h"

class MediumDifficulty : public Difficulty {
public:
	std::string GetDifficultyName();
	int GetObstacleSpacing();
	int GetObstacleGapHeight();
	int GetObstacleMaxShift();
	int GetHelicopterHorizontalVelocity();


private:
	const std::string DIFFICULTY_STRING = "Medium";
	const int OBSTACLE_SPACING = 165;
	const int OBSTACLE_GAP_HEIGHT = 110;
	const int OBSTACLE_MAX_SHIFT = 120;
	const int HELICOPTER_HORIZONTAL_VELOCITY = 125;

};
