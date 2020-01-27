#include "HardDifficulty.h"

using namespace std;

string HardDifficulty::GetDifficultyName() {
	return  DIFFICULTY_STRING;
}

int HardDifficulty::GetObstacleSpacing() {
	return OBSTACLE_SPACING;
}

int HardDifficulty::GetObstacleGapHeight() {
	return OBSTACLE_GAP_HEIGHT;
}
int HardDifficulty::GetObstacleMaxShift() {
	return OBSTACLE_MAX_SHIFT;
}
int HardDifficulty::GetHelicopterHorizontalVelocity() {
	return HELICOPTER_HORIZONTAL_VELOCITY;
}