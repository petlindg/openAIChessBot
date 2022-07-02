#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#ifndef SCREENWIDTH
	#define SCREENWIDTH 1200
#endif // !SCREENWIDTH
#ifndef SCREENHEIGHT
	#define SCREENHEIGHT 1000
#endif // !SCREENWIDTH


class Texture
{
public:
	//Texture(SDL_Surface* s, SDL_Renderer* r, SDL_Rect texture_rect, SDL_Rect window_rect, int x, int y);
	Texture();
	Texture(const Texture &t) = delete;
	Texture operator=(const Texture &t) = delete;
	~Texture();

	//Dont like the pointer attitude here. Maybe we can do const business?
	SDL_Texture* get_texture() {
		if (!_texture_generated) {
			printf("Warning, texture is not yet generated.");
			int a;
			std::cin >> a;
		}
		return _texture;
	}

	void gen_texture(SDL_Renderer*);
	void render(SDL_Renderer* r) const;
	void move(int x, int y);
	void init(const char* path, SDL_Rect texture_rect, SDL_Rect window_rect, int pos_x, int pos_y);

private:
	int _y;
	int _x;

	bool _texture_generated;
	bool _been_initialized;

	const char* _path;

	SDL_Texture* _texture;

protected: 
	SDL_Rect _window_rect;
	SDL_Rect _texture_rect;
};

