#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

#include "Constants.h"
#include "TextTexture.h"
#include "Input.h"

class Engine;

class MainMenu {
public:
	MainMenu(Engine* Engine) : _engine(Engine) {}

	bool Init();
	void Cleanup();
	void Update();
	void Draw();

	bool Active = true;
	bool NewGameRequested = false;
	int SelectedDifficulty = 0;

private:
	TTF_Font* _gameoverFont = NULL;
	TTF_Font* _regularTextFont = NULL;
	Engine* _engine = NULL;
	
	TextTexture* _gameoverTexture = NULL;
	TextTexture* _easyTexture = NULL;
	TextTexture* _easySelectedTexture = NULL;
	TextTexture* _mediumTexture = NULL;
	TextTexture* _mediumSelectedTexture = NULL;
	TextTexture* _hardTexture = NULL;
	TextTexture* _hardSelectedTexture = NULL;
	TextTexture* _pressSpaceTexture = NULL;

	SDL_Rect _gameoverRect;
	SDL_Rect _easyRect;
	SDL_Rect _mediumRect;
	SDL_Rect _hardRect;
	SDL_Rect _pressSpaceRect;

	const int GAMEOVER_FONT_SIZE = 48;
	const int REGULAR_FONT_SIZE = 32;

	bool _easySelected = true;
	bool _mediumSelected = false;
	bool _hardSelected = false;

	TextTexture* CreateTextureFromString(std::string Value, TTF_Font* Font, SDL_Color Color);
};