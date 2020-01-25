#pragma once

#include <SDL.h>
#include "ObstaclePair.h"
#include "Constants.h"

class Engine;

class ObstacleManager {
public:
	ObstacleManager(SDL_Texture* Texture, Engine* Engine) : _texture(Texture), _engine(Engine) {}

	bool Active = false;

	void Init();
	void Cleanup();
	void Draw();
	void Update();
	bool CheckPlayerCollision(SDL_Rect HelicopterRectangle);
	void Reset();

private:
	SDL_Texture* _texture = NULL;
	Engine* _engine = NULL;
	ObstaclePair _obstacles[Constants::OBSTACLE_PAIRS_TO_GENERATE];
	
	void GenerateNewYPos(int ObstacleIndex);
};