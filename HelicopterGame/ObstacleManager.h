#pragma once

#include <SDL.h>

class Engine;

class ObstactleManager {
public:
	ObstactleManager(SDL_Texture* Texture, Engine* Engine) : _texture(Texture), _engine(Engine) {}

	void Cleanup();
	void Draw();
	void Update();

private:
	SDL_Texture* _texture;
	Engine* _engine;
};