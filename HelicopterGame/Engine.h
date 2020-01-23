#pragma once

#include <stdio.h>
#include <string>

#include "Constants.h"
#include "Graphics.h"
#include "Input.h"
#include "Time.h"
#include "TextureManager.h"
#include "Helicopter.h"
#include "Background.h"
#include "ObstacleManager.h"

class Engine {
private:
	Graphics* _graphics = NULL;
	Input* _input = NULL;
	Time* _time = NULL;
	TextureManager* _textureManager = NULL;
	Helicopter* _helicopter = NULL;
	Background* _background = NULL;
	Background* _background2 = NULL;
	ObstactleManager* _obstacleManager = NULL;


public:
	bool Init(std::string WindowTitle);
	void Cleanup();
	void Run();

	//Getters
	Graphics* GetGraphics();
	Input* GetInput();
	Time* GetTime();
};