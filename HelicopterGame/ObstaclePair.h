#pragma once

#include <SDL.h>
#include "Constants.h"

class ObstaclePair {
public:
	float X;
	float TopY;
	float BottomY;
	SDL_Rect GetTopBoundingRectangle();
	SDL_Rect GetBottomBoundingRectangle();
};