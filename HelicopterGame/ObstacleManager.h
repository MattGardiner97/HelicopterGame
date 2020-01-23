#pragma once

#include <SDL.h>

class Engine;

class ObstacleManager {
public:
	ObstacleManager(SDL_Texture* Texture, Engine* Engine) : _texture(Texture), _engine(Engine) {}

	void Init();
	void Cleanup();
	void Draw();
	void Update();

private:
	SDL_Texture* _texture;
	Engine* _engine;



	float* _xPositions = NULL;
};