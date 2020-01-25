#include "EasyDifficulty.h"

using namespace std;

string EasyDifficulty::GetDifficultyName() {
	return  DIFFICULTY_STRING;
}

int EasyDifficulty::GetObstacleSpacing() {
	return OBSTACLE_SPACING;
}

int EasyDifficulty::GetObstacleGapHeight() {
	return OBSTACLE_GAP_HEIGHT;
}
int EasyDifficulty::GetObstacleMaxShift() {
	return OBSTACLE_MAX_SHIFT;
}
int EasyDifficulty::GetHelicopterHorizontalVelocity() {
	return HELICOPTER_HORIZONTAL_VELOCITY;
}