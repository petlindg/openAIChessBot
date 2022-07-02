#include "Texture.h"

#include <iostream>

//Might be wrong, fix the whole renderer thing at some point.
//I think we remove this in time. Better to keep classes consistent.


/*Texture::Texture(SDL_Surface* s, SDL_Renderer* r, SDL_Rect texture_rect, SDL_Rect window_rect, int x, int y) :
	_texture_rect(texture_rect),
	_window_rect(window_rect),
	_x(x),
	_y(y)
{
	_texture = SDL_CreateTextureFromSurface(r, s);

	if (_texture == NULL) {
		fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
		int a;
		std::cin >> a;
	}

	_texture_generated = true;
}*/
/*
Texture::Texture(const Texture &t)
{
	_y = t._y;
	_x = t._x;
	_texture_generated = t._texture_generated;
	_been_initialized = t._been_initialized;
	_path = t._path;
	_texture = t._texture;
	_window_rect = t._window_rect;
	_texture_rect = t._texture_rect;
}
*/



//IMplement rule of three. Can't be arsed atm. xd
Texture::Texture() : _texture_generated(false), _been_initialized(false)
{
}
Texture::~Texture()
{
	SDL_DestroyTexture(_texture);
}

void Texture::init(const char* path, SDL_Rect texture_rect, SDL_Rect window_rect, int pos_x, int pos_y)
{
	_texture_rect = texture_rect;
	_window_rect = window_rect;
	_x = pos_x;
	_y = pos_y;
	_path = path;
	_been_initialized = true;

	move(_x, _y);
}

void Texture::gen_texture(SDL_Renderer* r)
{
	if (!_been_initialized) {
		printf("Warning. Texture variables have not been intialized.");
		int a;
		std::cin >> a;
	}
	
	//Make this fast. We can load the image once and then do all pieces from same temp. This'll do for now.
	std::cout << _path << std::endl;
	SDL_Surface* temp = SDL_LoadBMP(_path);
	if (!temp) {
		printf("Error loading BMP in \"gen_texture\": %s\n", SDL_GetError());
		int a;
		std::cin >> a;
	}

	_texture = SDL_CreateTextureFromSurface(r, temp);

	SDL_FreeSurface(temp);

	_texture_generated = true;
}

void Texture::move(int x, int y)
{
	_x = x;
	_y = y;
	_window_rect.x = _x;
	_window_rect.y = _y;
}

void Texture::render(SDL_Renderer* r) const
{
	if (!_texture_generated) {
		printf("Warning. Texture has not been generated.");
		int a;
		std::cin >> a;
	}
	//printf("%i\n", _window_rect.x);
	SDL_RenderCopy(r, _texture, &_texture_rect, &_window_rect);
}
