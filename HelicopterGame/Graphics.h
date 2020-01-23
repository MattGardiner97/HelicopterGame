#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Constants.h"

class Graphics {
private:
	SDL_Window* _window = NULL;
	SDL_Renderer* _renderer = NULL;

public:
	bool Init(std::string WindowTitle);
	void Cleanup();
	SDL_Renderer* GetRenderer();
	void Clear();
	void Present();
	void RenderTexture(SDL_Texture* Texture, const SDL_Rect* TargetRect);
};