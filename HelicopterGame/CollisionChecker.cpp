#include "CollisionChecker.h"

namespace CollisionChecker {
	bool CheckCollision(SDL_Rect Rect1, SDL_Rect Rect2) {
		//Rect 1 top left
		if (PointInside(Rect1.x, Rect1.y, Rect2))
			return true;

		//Rect 1 top right
		if (PointInside(Rect1.x + Rect1.w, Rect1.y, Rect2))
			return true;

		//Rect 1 bottom left
		if (PointInside(Rect1.x, Rect1.y + Rect1.h, Rect2))
			return true;

		//Rect 1 bottom right
		if (PointInside(Rect1.x + Rect1.w, Rect1.y + Rect1.h, Rect2))
			return true;

		//Rect 2 top left
		if (PointInside(Rect2.x, Rect2.y, Rect1))
			return true;

		//Rect 2 top right
		if (PointInside(Rect2.x + Rect2.w, Rect2.y, Rect1))
			return true;

		//Rect 2 bottom left
		if (PointInside(Rect2.x, Rect2.y + Rect2.h, Rect1))
			return true;

		//Rect 2 Bottom right
		if (PointInside(Rect2.x + Rect2.w, Rect2.y + Rect2.h, Rect1))
			return true;

		return false;
	}

	bool PointInside(float X, float Y, SDL_Rect Rect)
	{
		if (X >= Rect.x && X <= Rect.x + Rect.w)
			if (Y >= Rect.y && Y <= Rect.y + Rect.h)
				return true;

		return false;
	}
}