#pragma once

class Input {
private:
	const int KEYS_BUFFER_SIZE = 322;
	SDL_Event e;
	bool _quitRequested = false;
	bool* _keysUp = NULL;
	bool* _keysDown = NULL;
	bool* _keysHeld = NULL;


public:
	bool Init();
	void Poll();
	bool IsQuitRequested();
	void Cleanup();
	bool KeyDown(SDL_Scancode Keycode);
	bool KeyPressed(SDL_Scancode Keycode);
	bool KeyUp(SDL_Scancode Keycode);
};

