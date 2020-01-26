#pragma once

#include <stdio.h>
#include <string>
#include <SDL_ttf.h>

#include "Constants.h"
#include "Graphics.h"
#include "Input.h"
#include "Time.h"
#include "TextureManager.h"
#include "Helicopter.h"
#include "Background.h"
#include "ObstacleManager.h"
#include "MainMenu.h"
#include "TextTextureGenerator.h"
#include "ScoreGUI.h"

#include "Difficulty.h"
#include "EasyDifficulty.h"

class Engine {
private:
	Graphics* _graphics = NULL;
	Input* _input = NULL;
	Time* _time = NULL;
	TextureManager* _textureManager = NULL;
	Helicopter* _helicopter = NULL;
	Background* _background = NULL;
	Background* _background2 = NULL;
	ObstacleManager* _obstacleManager = NULL;
	MainMenu* _mainMenu = NULL;
	ScoreGUI* _scoreGUI = NULL;
	TextTextureGenerator* _textTextureGenerator = NULL;
	bool GameActive = false;

	Difficulty* _currentDifficulty = NULL;
	EasyDifficulty* _easyDifficulty = NULL;


	void GameOver();
	void NewGame();

public:
	bool Init(std::string WindowTitle);
	void Cleanup();
	void Run();
	void IncrementScore();

	//Getters
	Graphics* GetGraphics();
	Input* GetInput();
	Time* GetTime();
	TextTextureGenerator* GetTextTextureGenerator();
	Difficulty* GetCurrentDifficulty();
};