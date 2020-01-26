#pragma once

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include "TextTexture.h"

class TextTextureGenerator {
public:
	TextTextureGenerator(SDL_Renderer* Renderer) : _renderer(Renderer) {}

	TextTexture* GenerateTexture(std::string Text,TTF_Font* Font, SDL_Color Color);

private:
	SDL_Renderer* _renderer = NULL;
};