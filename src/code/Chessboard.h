#pragma once

#include "Texture.h"

class Chessboard : public Texture
{
public:
	Chessboard();
	~Chessboard();

private:
	const char* _path;
};

