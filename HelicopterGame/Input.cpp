#include <SDL.h>
#include <vector>
#include <SDL.h>

#include "Input.h"

using namespace std;

bool Input::Init() {
	_keysUp = new bool[KEYS_BUFFER_SIZE];
	_keysDown = new bool[KEYS_BUFFER_SIZE];
	_keysHeld = new bool[KEYS_BUFFER_SIZE];

	for (int i = 0; i < KEYS_BUFFER_SIZE; i++)
	{
		_keysUp[i] = false;
		_keysDown[i] = false;
		_keysHeld[i] = false;
	}

	return true;
}

void Input::Poll() {
	for (int i = 0; i < KEYS_BUFFER_SIZE; i++)
	{
		_keysUp[i] = false;
		_keysDown[i] = false;
	}

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			_quitRequested = true;
		else if (e.type == SDL_KEYDOWN && e.key.repeat == false)
		{
		
		_keysDown[e.key.keysym.scancode] = true;
		_keysHeld[e.key.keysym.scancode] = true;
	}
		else if (e.type == SDL_KEYUP && e.key.repeat == false)
		{
			_keysUp[e.key.keysym.scancode] = true;
			_keysHeld[e.key.keysym.scancode] = false;
		}
	}
}

bool Input::IsQuitRequested() {
	return _quitRequested;
}

void Input::Cleanup() {
	delete[] _keysUp;
	delete[] _keysDown;
	delete[] _keysHeld;
}

bool Input::KeyDown(SDL_Scancode Keycode) {
	return _keysDown[Keycode] == true;
}

bool Input::KeyPressed(SDL_Scancode Keycode) {
	return _keysHeld[Keycode] == true;
}

bool Input::KeyUp(SDL_Scancode Keycode) {
	return _keysUp[Keycode] == true;
}