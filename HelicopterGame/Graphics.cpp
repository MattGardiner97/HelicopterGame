#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "Graphics.h"


using namespace std;

bool Graphics::Init(string WindowTitle) {
	const char* cWindowTitle = WindowTitle.c_str();
	_window = SDL_CreateWindow(cWindowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Constants::WINDOW_WIDTH,Constants::WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (_window == NULL)
	{
		printf("Error creating window. %s\n", SDL_GetError());
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == NULL) {
		printf("Error creating renderer. %s\n", SDL_GetError());
		return false;
	}

	SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("Error initialising SDL image. %s\n", IMG_GetError());
		return false;
	}

	return true;
}

void Graphics::Cleanup() {
	SDL_DestroyWindow(_window);
	_window = NULL;

	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
}

void Graphics::Clear() {
	SDL_RenderClear(_renderer);
}

void Graphics::Present() {
	SDL_RenderPresent(_renderer);
}

void Graphics::RenderTexture(SDL_Texture* Texture,const SDL_Rect* TargetRect ) {
	SDL_RenderCopy(_renderer, Texture, NULL, TargetRect);
}

SDL_Renderer* Graphics::GetRenderer()
{
	return _renderer;
}