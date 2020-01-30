#include "ScoreGUI.h"
#include "Engine.h"
#include <iostream>

void ScoreGUI::Cleanup() {
	CleanupTexture();

	if (_font != NULL)
	{
		TTF_CloseFont(_font);
		_font = NULL;
	}
}

void ScoreGUI::CleanupTexture() {
	if (_texture != NULL)
	{
		_texture->Cleanup();
		delete _texture;
		_texture = NULL;
	}
}

bool ScoreGUI::Init() {
	_font = TTF_OpenFont(Constants::FONT_NAME.c_str(), FONT_SIZE);
	if (_font == NULL)
		return false;

}

void ScoreGUI::UpdateScore(int NewScore) {
	Score = NewScore;

	CleanupTexture();

	SDL_Color blackColor = { 0,0,0 };
	_texture = _engine->GetTextTextureGenerator()->GenerateTexture("Score: " + std::to_string(Score), _font, blackColor);

	rect.x = 10;
	rect.y = 10;
	rect.w = _texture->TextureWidth;
	rect.h = _texture->TextureHeight;


}

void ScoreGUI::Draw() {
	if(Active == true)

	_engine->GetGraphics()->RenderTexture(_texture->Texture, &rect);
}