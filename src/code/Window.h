#pragma once

#include <SDL2/SDL.h>

class Window
{
public:
	Window(const char* title);
	~Window();

	SDL_Window* get_window() { return window; }

private:
	SDL_Window* window;
};

