#include "MediumDifficulty.h"

using namespace std;

string MediumDifficulty::GetDifficultyName() {
	return  DIFFICULTY_STRING;
}

int MediumDifficulty::GetObstacleSpacing() {
	return OBSTACLE_SPACING;
}

int MediumDifficulty::GetObstacleGapHeight() {
	return OBSTACLE_GAP_HEIGHT;
}
int MediumDifficulty::GetObstacleMaxShift() {
	return OBSTACLE_MAX_SHIFT;
}
int MediumDifficulty::GetHelicopterHorizontalVelocity() {
	return HELICOPTER_HORIZONTAL_VELOCITY;
}