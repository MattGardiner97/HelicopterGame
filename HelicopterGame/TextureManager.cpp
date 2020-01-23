#include "TextureManager.h"

SDL_Texture* TextureManager::LoadFromFile(std::string Filename) {
	SDL_Texture* result = NULL;

	SDL_Surface* loadedSurface = IMG_Load(Filename.c_str());
	if (loadedSurface == NULL)
	{
		printf("Error loading image %s. %s\n", Filename, IMG_GetError());
		return NULL;
	}
	
	result = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
	if (result == NULL)
	{
		printf("Error loading image %s. %s\n", Filename, IMG_GetError());
		return NULL;
	}

	SDL_FreeSurface(loadedSurface);

	return result;
}