#include "Piece.h"

#include <iostream>

Piece::Piece(int x, int y) :
	_pieces_path(".\\src\\textures\\chess_pieces.bmp")
{
	init(_pieces_path,{ 0, 0, PIECEWIDTH, PIECEHEIGHT }, { x, y, PIECEWIDTH, PIECEHEIGHT }, x, y);
}
Piece::~Piece()
{
}

void Piece::set_piece(std::pair<int, int> piece_type) 
{
	_texture_rect = { piece_type.first * PIECEWIDTH, piece_type.second * PIECEHEIGHT, PIECEWIDTH, PIECEHEIGHT };
}