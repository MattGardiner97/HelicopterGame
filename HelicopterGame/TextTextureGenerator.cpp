#include "TextTextureGenerator.h"

TextTexture* TextTextureGenerator::GenerateTexture(std::string Text, TTF_Font* Font, SDL_Color Color) {
	SDL_Surface* textSurface = TTF_RenderText_Solid(Font, Text.c_str(), Color);
	if (textSurface == NULL)
	{
		printf("Error creating text surface. %s\n", TTF_GetError());
		return NULL;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, textSurface);
	if (texture == NULL)
	{
		printf("Error creating texture. %s\n", SDL_GetError());
		return NULL;
	}

	TextTexture* result = new TextTexture(texture, textSurface->w, textSurface->h);

	SDL_FreeSurface(textSurface);

	return result;
}