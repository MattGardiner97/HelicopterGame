#include "Engine.h"
#include "MainMenu.h"

bool MainMenu::Init() {
	_gameoverFont = TTF_OpenFont(Constants::FONT_NAME.c_str(), GAMEOVER_FONT_SIZE);
	if (_gameoverFont == NULL)
		return false;

	_regularTextFont = TTF_OpenFont(Constants::FONT_NAME.c_str(), REGULAR_FONT_SIZE);
	if (_regularTextFont == NULL)
		return false;

	SDL_Color blackColor = { 0,0,0 };
	SDL_Color selectedColor = { 255,0,0 };
	_gameoverTexture = CreateTextureFromString("Game Over", _gameoverFont, blackColor);
	if (_gameoverTexture == NULL)
		return false;

	_easyTexture = CreateTextureFromString("1:Easy", _regularTextFont, blackColor);
	if (_easyTexture == NULL)
		return false;
	_mediumTexture = CreateTextureFromString("2:Medium", _regularTextFont, blackColor);
	if (_mediumTexture == NULL)
		return false;
	_hardTexture = CreateTextureFromString("3:Hard", _regularTextFont, blackColor);
	if (_hardTexture == NULL)
		return false;

	_easySelectedTexture = CreateTextureFromString("1:Easy", _regularTextFont, selectedColor);
	if (_easySelectedTexture == NULL)
		return false;
	_mediumSelectedTexture = CreateTextureFromString("2:Medium", _regularTextFont, selectedColor);
	if (_mediumSelectedTexture == NULL)
		return false;
	_hardSelectedTexture = CreateTextureFromString("3:Hard", _regularTextFont, selectedColor);
	if (_hardSelectedTexture == NULL)
		return false;

	_gameoverRect.x = (Constants::WINDOW_WIDTH / 2) - (_gameoverTexture->TextureWidth / 2);
	_gameoverRect.y = (Constants::WINDOW_HEIGHT / 4) - (_gameoverTexture->TextureHeight / 2);
	_gameoverRect.w = _gameoverTexture->TextureWidth;
	_gameoverRect.h = _gameoverTexture->TextureHeight;

	_easyRect.x = (Constants::WINDOW_WIDTH / 4) - (_easyTexture->TextureWidth / 2);
	_easyRect.y = (Constants::WINDOW_HEIGHT / 2) - (_easyTexture->TextureHeight / 2);
	_easyRect.w = _easyTexture->TextureWidth;
	_easyRect.h = _easyTexture->TextureHeight;

	_mediumRect.x = (Constants::WINDOW_WIDTH / 2) - (_mediumTexture->TextureWidth / 2);
	_mediumRect.y = (Constants::WINDOW_HEIGHT / 2) - (_mediumTexture->TextureHeight / 2);
	_mediumRect.w = _mediumTexture->TextureWidth;
	_mediumRect.h = _mediumTexture->TextureHeight;

	_hardRect.x = (Constants::WINDOW_WIDTH / 4 * 3) - (_hardTexture->TextureWidth / 2);
	_hardRect.y = (Constants::WINDOW_HEIGHT / 2) - (_hardTexture->TextureHeight / 2);
	_hardRect.w = _hardTexture->TextureWidth;
	_hardRect.h = _hardTexture->TextureHeight;



	return true;
}

void MainMenu::Cleanup() {
	TTF_CloseFont(_gameoverFont);
	_gameoverFont = NULL;
	TTF_CloseFont(_regularTextFont);
	_regularTextFont = NULL;

	if (_gameoverTexture != NULL)
	{
		_gameoverTexture->Cleanup();
		delete _gameoverTexture;
		_gameoverTexture = NULL;
	}
	if (_easyTexture != NULL)
	{
		_easyTexture->Cleanup();
		delete _easyTexture;
		_easyTexture = NULL;
	}
	if (_mediumTexture != NULL)
	{
		_mediumTexture->Cleanup();
		delete _mediumTexture;
		_mediumTexture = NULL;
	}
	if (_hardTexture != NULL)
	{
		_hardTexture->Cleanup();
		delete _hardTexture;
		_hardTexture = NULL;
	}

	if (_easySelectedTexture != NULL)
	{
		_easySelectedTexture->Cleanup();
		delete _easySelectedTexture;
		_easySelectedTexture = NULL;
	}
	if (_mediumSelectedTexture != NULL)
	{
		_mediumSelectedTexture->Cleanup();
		delete _mediumSelectedTexture;
		_mediumSelectedTexture = NULL;
	}
	if (_hardSelectedTexture != NULL)
	{
		_hardSelectedTexture->Cleanup();
		delete _hardSelectedTexture;
		_hardSelectedTexture = NULL;
	}

	return;
}

void MainMenu::Update() {
	Input* input = _engine->GetInput();

	if (input->KeyDown(SDL_SCANCODE_SPACE))
		NewGameRequested = true;

	if (input->KeyDown(SDL_SCANCODE_1))
	{
		SelectedDifficulty = 0;
		_easySelected = true;
		_mediumSelected = false;
		_hardSelected = false;
	}
	else if (input->KeyDown(SDL_SCANCODE_2))
	{
		SelectedDifficulty = 1;
		_easySelected = false;
		_mediumSelected = true;
		_hardSelected = false;
	}
	else if (input->KeyDown(SDL_SCANCODE_3))
	{
		SelectedDifficulty = 2;
		_easySelected = false;
		_mediumSelected = false;
		_hardSelected = true;
	}
}

TextTexture* MainMenu::CreateTextureFromString(std::string Value, TTF_Font* Font, SDL_Color Color)
{
	SDL_Surface* textSurface = TTF_RenderText_Solid(Font, Value.c_str(), Color);
	if (textSurface == NULL)
	{
		printf("Error creating text surface. %s\n", TTF_GetError());
		return NULL;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(_engine->GetGraphics()->GetRenderer(), textSurface);
	if (texture == NULL)
	{
		printf("Error creating texture. %s\n", SDL_GetError());
		return NULL;
	}

	TextTexture* result = new TextTexture(texture, textSurface->w, textSurface->h);

	SDL_FreeSurface(textSurface);

	return result;
}

void MainMenu::Draw() {
	if (Active == false)
		return;

	_engine->GetGraphics()->RenderTexture(_gameoverTexture->Texture, &_gameoverRect);

	if (_easySelected == true)
		_engine->GetGraphics()->RenderTexture(_easySelectedTexture->Texture, &_easyRect);
	else
		_engine->GetGraphics()->RenderTexture(_easyTexture->Texture, &_easyRect);

	if (_mediumSelected == true)
		_engine->GetGraphics()->RenderTexture(_mediumSelectedTexture->Texture, &_mediumRect);
	else
		_engine->GetGraphics()->RenderTexture(_mediumTexture->Texture, &_mediumRect);

	if (_hardSelected == true)
		_engine->GetGraphics()->RenderTexture(_hardSelectedTexture->Texture, &_hardRect);
	else
		_engine->GetGraphics()->RenderTexture(_hardTexture->Texture, &_hardRect);
}