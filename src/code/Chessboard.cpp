#include "Chessboard.h"

/*	SDL_Surface* chess_board_temp = SDL_LoadBMP(chess_board);
	SDL_Texture* chess_board_texture = SDL_CreateTextureFromSurface(_renderer, chess_board_temp);
	SDL_FreeSurface(chess_board_temp);
	SDL_RenderCopy(_renderer, chess_board_texture, &chess_board_textureRect, &chess_board_windowRect);
	SDL_free(chess_board_texture); */

Chessboard::Chessboard() : _path(".\\src\\textures\\chess_board_other_dim.bmp")
{
	init(_path, { 0, 0, 800, 800 }, { 0, 0, 800, 800 }, 200, 100);
}
Chessboard::~Chessboard()
{
}
