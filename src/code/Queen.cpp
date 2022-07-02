#include "Queen.h"



Queen::Queen(int x, int y, std::pair<int, int> piece) :
	Piece(x, y),
	_x(x),
	_y(y)
{	
	set_piece(piece);
}


Queen::~Queen()
{
}
