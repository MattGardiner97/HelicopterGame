#pragma once

#include <SDL.h>

class TextTexture
{
public:
	TextTexture(SDL_Texture* Texture, int Width, int Height) : Texture(Texture), TextureWidth(Width), TextureHeight(Height) {}

	void Cleanup();

	SDL_Texture* Texture;
	int TextureWidth;
	int TextureHeight;
};