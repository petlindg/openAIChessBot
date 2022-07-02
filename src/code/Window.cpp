#include "Window.h"



Window::Window(const char* title)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1000, SDL_WINDOW_SHOWN);
}


Window::~Window()
{
}
