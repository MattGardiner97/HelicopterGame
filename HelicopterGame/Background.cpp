#include "Background.h"
#include "Engine.h"

void Background::Cleanup() {
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}

void Background::Draw() {
	Graphics* graphics = _engine->GetGraphics();

	SDL_Rect rect;
	rect.x = this->_x;
	rect.y = 0;
	rect.w = Constants::WINDOW_WIDTH;
	rect.h = Constants::WINDOW_HEIGHT;

	graphics->RenderTexture(_texture, &rect);
}

void Background::Update() {
	Time* time = _engine->GetTime();

	this->_x -= Constants::BACKGROUND_SCROLL_SPEED * time->GetDeltaTime();

	if (this->_x <= -Constants::WINDOW_WIDTH)
		this->_x = Constants::WINDOW_WIDTH-1;
}

void Background::SetX(float Value) {
	this->_x = Value;
}