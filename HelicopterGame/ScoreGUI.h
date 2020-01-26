#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include "TextTexture.h"


class Engine;

class ScoreGUI {
public:
	ScoreGUI(Engine* Engine) : _engine(Engine) {}

	void Cleanup();
	bool Init();
	void UpdateScore(int NewScore);
	void Draw();

	int Score = 0;
	bool Active = true;

private:
	const int FONT_SIZE = 16;

	TextTexture* _texture = NULL;
	Engine* _engine = NULL;
	TTF_Font* _font = NULL;
	SDL_Rect rect;

	void CleanupTexture();


};