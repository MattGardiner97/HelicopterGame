#pragma once

#include "Constants.h"
#include "Graphics.h"
#include "Input.h"
#include "Time.h"
#include "TextureManager.h"
#include "Helicopter.h"


class Engine;

class Helicopter {
public:
	Helicopter(SDL_Texture* Texture, Engine* Engine) : _texture(Texture), _engine(Engine), _x(0), _y(0) {

	}

	void Update();
	void Cleanup();
	void Draw();

private:
	SDL_Texture* _texture = NULL;
	Engine* _engine = NULL;
	float _x;
	float _y;
	float _horizontalVelocity;
	float _verticalVelocity;
};