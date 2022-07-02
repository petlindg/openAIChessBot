#include "Renderer.h"


Renderer::Renderer(Window w)
{
	_renderer = SDL_CreateRenderer(w.get_window(), -1, 0);
	_window = w.get_window();
}


Renderer::~Renderer()
{
}

void Renderer::draw(std::vector<Texture*> &tv)
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);	
	SDL_RenderClear(_renderer);

	for (int i = 0; i < tv.size(); i++)
	{
		tv[i]->render(_renderer);
	}

	SDL_UpdateWindowSurface(_window);
	SDL_RenderPresent(_renderer);
}
