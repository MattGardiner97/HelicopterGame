#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class TextureManager {
public:
	TextureManager(SDL_Renderer* Renderer) : _renderer(Renderer)
	{

	}

	SDL_Texture* LoadFromFile(std::string Filename);

private:
	SDL_Renderer* _renderer = NULL;
};