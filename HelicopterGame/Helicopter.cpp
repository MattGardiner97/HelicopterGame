#include "Helicopter.h"
#include "Engine.h"

void Helicopter::Draw() {
	if (Active == false)
		return;

	SDL_Rect rect;
	rect.x = this->_x;
	rect.y = this->_y;
	rect.w = Constants::HELICOPTER_SIZE;
	rect.h = Constants::HELICOPTER_SIZE;

	_engine->GetGraphics()->RenderTexture(_texture, &rect);
}

void Helicopter::Cleanup() {
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}

void Helicopter::Update() {
	if (Active == false)
		return;

	Input* input = _engine->GetInput();
	Time* time = _engine->GetTime();

	this->_verticalVelocity += Constants::GRAVITY * time->GetDeltaTime();

	if (input->KeyPressed(SDL_SCANCODE_SPACE))
	{
		this->_verticalVelocity -= Constants::HELICOPTER_VERTICAL_ACCELERATION * time->GetDeltaTime();
	}

	this->_y += this->_verticalVelocity;
}

SDL_Rect Helicopter::GetBoundingRectangle() {
	SDL_Rect result;
	result.x = this->_x;
	result.y = this->_y;
	result.w = Constants::HELICOPTER_SIZE;
	result.h = Constants::HELICOPTER_SIZE;
	return result;
}

void Helicopter::Reset() {
	Active = true;
	_y = Constants::WINDOW_HEIGHT / 2;
	_x = Constants::HELICOPTER_STARTING_POSITION;
	this->_verticalVelocity = 0;
}

bool Helicopter::IsOffScreen()
{
	if (_y <= 0 || _y + Constants::HELICOPTER_SIZE >= Constants::WINDOW_HEIGHT)
		return true;
	return false;
}