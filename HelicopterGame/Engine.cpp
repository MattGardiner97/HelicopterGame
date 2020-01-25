#include <stdio.h>
#include <string>

#include "Engine.h"

using namespace std;

bool Engine::Init(string WindowTitle) {
	TTF_Init();

	_graphics = new Graphics;
	if (_graphics->Init(WindowTitle) == false)
		return false;

	_textureManager = new TextureManager(_graphics->GetRenderer());

	_time = new Time;
	if (_time->Init() == false)
		return false;

	_input = new Input;
	if (_input->Init() == false)
		return false;

	_mainMenu = new MainMenu(this);
	if (_mainMenu->Init() == false)
		return false;

	_easyDifficulty = new EasyDifficulty;
	_currentDifficulty = _easyDifficulty;

	//Load helicopter texture
	SDL_Texture* helicopterTexture = _textureManager->LoadFromFile(Constants::HELICOPTER_IMAGE_NAME);
	if (helicopterTexture == NULL)
		return false;
	//Load background texture
	SDL_Texture* backgroundTexture = _textureManager->LoadFromFile(Constants::BACKGROUND_IMAGE_NAME);
	if (backgroundTexture == NULL)
		return false;
	//Load obstacle texture
	SDL_Texture* obstacleTexture = _textureManager->LoadFromFile(Constants::OBSTACLE_IMAGE_NAME);
	if (obstacleTexture == NULL)
		return false;

	_helicopter = new Helicopter(helicopterTexture, this);
	_background = new Background(backgroundTexture, this);
	_background2 = new Background(backgroundTexture, this);
	_background2->SetX(Constants::WINDOW_WIDTH - 1);
	_obstacleManager = new ObstacleManager(obstacleTexture, this);
	_obstacleManager->Init();

	return true;
}

void Engine::Cleanup() {
	if (_graphics != NULL)
	{
		_graphics->Cleanup();
		delete _graphics;
		_graphics = NULL;
	}

	if (_time != NULL) {
		_time->Cleanup();
		delete _time;
		_time = NULL;
	}

	if (_input != NULL)
	{
		_input->Cleanup();
		delete _input;
		_input = NULL;
	}

	if (_helicopter != NULL)
	{
		_helicopter->Cleanup();
		delete _helicopter;
		_helicopter = NULL;
	}

	if (_background != NULL)
	{
		_background->Cleanup();
		delete _background;
		_background = NULL;
	}

	if (_background2 != NULL)
	{
		_background2->Cleanup();
		delete _background2;
		_background2 = NULL;
	}

	if (_obstacleManager != NULL)
	{
		_obstacleManager->Cleanup();
		delete _obstacleManager;
		_obstacleManager = NULL;
	}

	_currentDifficulty = NULL;
	if (_easyDifficulty != NULL)
	{
		delete _easyDifficulty;
		_easyDifficulty = NULL;
	}

	if (_mainMenu != NULL)
	{
		_mainMenu->Cleanup();
		delete _mainMenu;
		_mainMenu = NULL;
	}

	SDL_Quit();
	IMG_Quit();
}

void Engine::Run() {
	while (_input->IsQuitRequested() == false) {
		//Update Timer
		_time->Update();

		//Update Input
		_input->Poll();

		//Update
		_background->Update();
		_background2->Update();
		_helicopter->Update();
		_obstacleManager->Update();
		_mainMenu->Update();

		if (GameActive == false && _mainMenu->NewGameRequested == true)
			NewGame();

		//Check collisions
		if (_obstacleManager->CheckPlayerCollision(_helicopter->GetBoundingRectangle()))
			GameOver();
		//Check helicopter offscreen
		if (_helicopter->IsOffScreen())
			GameOver();

		//Clear render target
		_graphics->Clear();

		//Draw helicopter
		_background->Draw();
		_background2->Draw();
		_obstacleManager->Draw();
		_helicopter->Draw();
		_mainMenu->Draw();


		//Present render target
		_graphics->Present();

		SDL_Delay(8);
	}
}

Input* Engine::GetInput() {
	return _input;
}

Graphics* Engine::GetGraphics() {
	return _graphics;
}

Time* Engine::GetTime() {
	return _time;
}

Difficulty* Engine::GetCurrentDifficulty() {
	return _currentDifficulty;
}

void Engine::GameOver() {
	GameActive = false;
	_mainMenu->Active = true;
	_obstacleManager->Active = false;
	_helicopter->Active = false;
}

void Engine::NewGame() {
	_mainMenu->NewGameRequested = false;

	switch (_mainMenu->SelectedDifficulty)
	{
	case 0:
		_currentDifficulty = _easyDifficulty;
		break;
	}


	GameActive = true;
	_mainMenu->Active = false;
	_obstacleManager->Reset();
	_helicopter->Reset();
}