#pragma once

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(int x, int y, std::pair<int, int> piece);
	~Queen();

private:
	int _x, _y;
};

