#pragma once

#include <SDL.h>
namespace CollisionChecker {
	bool CheckCollision(SDL_Rect Rect1, SDL_Rect Rect2);
	bool PointInside(float X, float Y, SDL_Rect Rect);
}