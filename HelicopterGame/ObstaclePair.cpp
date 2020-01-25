#include "ObstaclePair.h"

SDL_Rect ObstaclePair::GetTopBoundingRectangle() {
	SDL_Rect result;
	result.x = X;
	result.y = TopY;
	result.w = Constants::OBSTACLE_WIDTH;
	result.h = Constants::OBSTACLE_HEIGHT;
	return result;
}
SDL_Rect ObstaclePair::GetBottomBoundingRectangle() {
	SDL_Rect result;
	result.x = X;
	result.y = BottomY;
	result.w = Constants::OBSTACLE_WIDTH;
	result.h = Constants::OBSTACLE_HEIGHT;
	return result;
}