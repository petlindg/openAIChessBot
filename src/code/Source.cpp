#include <iostream>
#include <SDL2/SDL.h>
#include "Window.h"
#include "Renderer.h"
#include "Queen.h"
#include "Pawn.h"
#include "Chessboard.h"

#undef main

int main() 
{
	std::cout << "Hello World!";

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "Could not initialise SDL: %s\n", SDL_GetError());
		exit(-1);
	}

	Window window("Test");
	Renderer renderer(window);

	Chessboard chessboard;
	Queen white_queen(100, 100, std::pair<int, int>(1, 0));
	Queen black_queen(500, 100, std::pair<int, int>(1, 1));
	Pawn pawn;

	std::vector<Texture*> textures = {&chessboard, &white_queen, &black_queen};

	for (int i = 0; i < textures.size(); i++)
		textures[i]->gen_texture(renderer.get_renderer());


	bool run = true;
	while (run) {
		SDL_Event evnt;

		while (SDL_PollEvent(&evnt)) {
			switch (evnt.type) {
			case SDL_KEYUP:
				printf("Key press detected\n");
				switch (evnt.key.keysym.sym) {
				case SDLK_a:
					break;
				case SDLK_w:
					break;
				case SDLK_s:
					break;
				case SDLK_d:
					break;
				}
				break;

			case SDL_KEYDOWN:
				printf("Key release detected\n");
				switch (evnt.key.keysym.sym) {
				case SDLK_a:
					break;
				case SDLK_w:
					break;
				case SDLK_s:
					break;
				case SDLK_d:
					break;
				}
				break;

			case SDL_QUIT:
				run = false;
				break;
			
			default:
				break;
			}
		}
		renderer.draw(textures);
	}

	SDL_Quit();

	return 0;
}