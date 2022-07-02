#pragma once

#include <vector>

#include "Window.h"
#include "Texture.h"

class Renderer
{
public:
	Renderer(Window);
	~Renderer();

	void draw(std::vector<Texture*> &tv);
	
	SDL_Renderer* get_renderer() { return _renderer; }

private:
	SDL_Renderer* _renderer;
	SDL_Window* _window;
};

