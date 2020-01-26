#include "ObstacleManager.h"
#include "Engine.h"
#include <stdlib.h>
#include "ObstaclePair.h"
#include "CollisionChecker.h"


void ObstacleManager::Init() {
	Reset();
	Active = false;
}

void ObstacleManager::Cleanup() {
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}

void ObstacleManager::Draw() {
	if(Active == false)
		return;

	Difficulty* currentDifficulty = _engine->GetCurrentDifficulty();

	//For each obstacle pair
	for (int i = 0; i < Constants::OBSTACLE_PAIRS_TO_GENERATE; i++)
	{
		SDL_Rect topRect;
		topRect.x = _obstacles[i].X;
		topRect.y = _obstacles[i].TopY;
		topRect.w = Constants::OBSTACLE_WIDTH;
		topRect.h = Constants::OBSTACLE_HEIGHT;

		SDL_Rect bottomRect;
		bottomRect.x = _obstacles[i].X;
		bottomRect.y = _obstacles[i].BottomY;
		bottomRect.w = Constants::OBSTACLE_WIDTH;
		bottomRect.h = Constants::OBSTACLE_HEIGHT;

		Graphics* graphics = _engine->GetGraphics();
		graphics->RenderTexture(_texture, &topRect);
		graphics->RenderTexture(_texture, &bottomRect);

	}
}

void ObstacleManager::Update() {
	if (Active == false)
		return;

	Time* time = _engine->GetTime();
	Difficulty* currentDifficulty = _engine->GetCurrentDifficulty();

	for (int i = 0; i < Constants::OBSTACLE_PAIRS_TO_GENERATE; i++)
	{
		_obstacles[i].X -= currentDifficulty->GetHelicopterHorizontalVelocity() * time->GetDeltaTime();
	}

	for (int i = 0; i < Constants::OBSTACLE_PAIRS_TO_GENERATE; i++)
	{
		if (_obstacles[i].X <= 0 - Constants::OBSTACLE_WIDTH)
		{
			_engine->IncrementScore();

			float prevXPos = 0;
			if (i == 0)
				prevXPos = _obstacles[Constants::OBSTACLE_PAIRS_TO_GENERATE - 1].X;
			else
				prevXPos = _obstacles[i - 1].X;

			_obstacles[i].X = prevXPos + Constants::OBSTACLE_WIDTH + currentDifficulty->GetObstacleSpacing();
			GenerateNewYPos(i);
		}
	}

}

void ObstacleManager::GenerateNewYPos(int ObstacleIndex) {
	Difficulty* currentDifficulty = _engine->GetCurrentDifficulty();

	float centrePoint = Constants::WINDOW_HEIGHT / 2;
	float shift = rand() % currentDifficulty->GetObstacleMaxShift();
	if (rand() % 2 == 1)
		shift *= -1;

	centrePoint += shift;

	float topYPos = centrePoint - (currentDifficulty->GetObstacleGapHeight() / 2) - Constants::OBSTACLE_HEIGHT;
	float bottomYPos = centrePoint + (currentDifficulty->GetObstacleGapHeight() / 2);

	_obstacles[ObstacleIndex].TopY = topYPos;
	_obstacles[ObstacleIndex].BottomY = bottomYPos;
}

bool ObstacleManager::CheckPlayerCollision(SDL_Rect HelicopterRectangle) {
	for (int i = 0; i < Constants::OBSTACLE_PAIRS_TO_GENERATE; i++)
	{
		if (CollisionChecker::CheckCollision(HelicopterRectangle, _obstacles[i].GetTopBoundingRectangle()))
			return true;
		if (CollisionChecker::CheckCollision(HelicopterRectangle, _obstacles[i].GetBottomBoundingRectangle()))
			return true;
	}

	return false;
}

void ObstacleManager::Reset() {
	Active = true;

	srand(time(NULL)); //Give the random number generator a seed based on the current time
	Difficulty* currentDifficulty = _engine->GetCurrentDifficulty();

	for (int i = 0; i < Constants::OBSTACLE_PAIRS_TO_GENERATE; i++)
	{
		if (i == 0)
			_obstacles[i].X = Constants::HELICOPTER_STARTING_POSITION +  currentDifficulty->GetObstacleSpacing();
		else
			_obstacles[i].X = Constants::HELICOPTER_STARTING_POSITION + _obstacles[i - 1].X + Constants::OBSTACLE_WIDTH + currentDifficulty->GetObstacleSpacing();

		GenerateNewYPos(i);
	}
}