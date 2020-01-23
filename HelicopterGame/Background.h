#pragma once
#include <SDL.h>

class Engine;

class Background {
public:
	Background(SDL_Texture* Texture,Engine* Engine) : _texture(Texture),_engine(Engine) {}
	void Update();
	void Cleanup();
	void Draw();
	void SetX(float Value);

private:
	Engine* _engine;
	SDL_Texture* _texture;
	float _x = 0;
	float _y = 0;
};