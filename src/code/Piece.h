#pragma once

#include "Texture.h"

#include <iostream>

#define PIECEWIDTH 780 / 6
#define PIECEHEIGHT 260 / 2

class Piece : public Texture
{
public:
	Piece(int x, int y);
	~Piece();

	void set_piece(std::pair<int, int> piece_type);

protected:
	const char* _pieces_path;
};

