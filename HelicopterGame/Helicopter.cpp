#include "Helicopter.h"
#include "Engine.h"

void Helicopter::Draw() {
	SDL_Rect rect;
	rect.x = this->_x;
	rect.y = this->_y;
	rect.w = 50;
	rect.h = 50;

	_engine->GetGraphics()->RenderTexture(_texture, &rect);
}

void Helicopter::Cleanup() {
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}

void Helicopter::Update() {
	Input* input = _engine->GetInput();
	Time* time = _engine->GetTime();

	this->_verticalVelocity += Constants::GRAVITY * time->GetDeltaTime();

	if (input->KeyPressed(SDL_SCANCODE_SPACE))
	{
		this->_verticalVelocity -= Constants::HELICOPTER_VERTICAL_ACCELERATION * time->GetDeltaTime();
	}

	this->_y += this->_verticalVelocity;
}