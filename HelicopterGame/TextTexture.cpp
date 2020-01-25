#include "TextTexture.h"

void TextTexture::Cleanup() {
	SDL_DestroyTexture(this->Texture);
	this->Texture = NULL;
}