#include "ObstacleManager.h"
#include "Engine.h"


void ObstacleManager::Init() {
	_xPositions = new float[Constants::OBSTACLES_TO_GENERATE];
	for (int i = 0; i < Constants::OBSTACLES_TO_GENERATE; i++)
		_xPositions[i] = 50 + (50 * i);
}

void ObstacleManager::Cleanup() {
	SDL_DestroyTexture(_texture);
	_texture = NULL;

	if (_xPositions != NULL)
	{
		delete[] _xPositions;
		_xPositions = NULL;
	}
}

void ObstacleManager::Draw() {
	for (int i = 0; i < Constants::OBSTACLES_TO_GENERATE;i++)
	{

		SDL_Rect rect;
		rect.x = _xPositions[i];
		rect.y = 0;
		rect.w = Constants::OBSTACLE_WIDTH;
		rect.h = Constants::OBSTACLE_HEIGHT;

		Graphics* graphics = _engine->GetGraphics();
		graphics->RenderTexture(_texture, &rect);
	}
}

void ObstacleManager::Update() {

	Time* time = _engine->GetTime();

	for (int i = 0; i < Constants::OBSTACLES_TO_GENERATE; i++)
	{
		_xPositions[i] -= Constants::HELICOPTER_HORIZONTAL_VELOCITY * time->GetDeltaTime();
	}

}