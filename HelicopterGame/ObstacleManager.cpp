#include "ObstacleManager.h"
#include "Engine.h"

void ObstacleManager::Cleanup() {
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}

void ObstacleManager::Draw() {

}

void ObstacleManager::Update() {

}