#ifndef TETROMINO_H
#define TETROMINO_H
#include <string>

class Tetromino
{
public:
	//Attributes:
	std::wstring* pTetromino;
	int nCurrentPiece;		//Index into tetromino array
	int nCurrentRotation;	//Code for how many degrees tetromino matrix has been rotated.
	int nCurrentX = 6;
	int nCurrentY = 0;

	//Constructor:
	Tetromino();

	//Methods:
	int GetNewPiece();
	int GetCurrentX();
	int GetCurrentY();
	int Rotate(int nPosX, int nPosY, int nCurrentRotation);

	//Destructor:
	~Tetromino();

};

#endif TETROMINO_H