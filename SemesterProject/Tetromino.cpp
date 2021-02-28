#include "Tetromino.h"
#include "PlayField.h"
#include <string>

Tetromino::Tetromino()
{
	pTetromino = new std::wstring[7];

	pTetromino[0].append(L"..X.");
	pTetromino[0].append(L"..X.");
	pTetromino[0].append(L"..X.");
	pTetromino[0].append(L"..X.");

	pTetromino[1].append(L"..X.");
	pTetromino[1].append(L".XX.");
	pTetromino[1].append(L"..X.");
	pTetromino[1].append(L"....");

	pTetromino[2].append(L"....");
	pTetromino[2].append(L".XX.");
	pTetromino[2].append(L".XX.");
	pTetromino[2].append(L"....");

	pTetromino[3].append(L"..X.");
	pTetromino[3].append(L".XX.");
	pTetromino[3].append(L".X..");
	pTetromino[3].append(L"....");

	pTetromino[4].append(L".X..");
	pTetromino[4].append(L".XX.");
	pTetromino[4].append(L"..X.");
	pTetromino[4].append(L"....");

	pTetromino[5].append(L"....");
	pTetromino[5].append(L".X..");
	pTetromino[5].append(L".X..");
	pTetromino[5].append(L".XX.");

	pTetromino[6].append(L"....");
	pTetromino[6].append(L"..X.");
	pTetromino[6].append(L"..X.");
	pTetromino[6].append(L".XX.");
}

int Tetromino::GetNewPiece()
{
	//Field width = 12, so this spawns the piece in the top middle of the board.
	nCurrentX = 6;
	nCurrentY = 0;

	//Create new piece and give default orientation.
	nCurrentPiece = rand() % 7;
	nCurrentRotation = 0;
	return nCurrentPiece;
}

int Tetromino::GetCurrentX()
{
	return nCurrentX;
}

int Tetromino::GetCurrentY()
{
	return nCurrentY;
}

int Tetromino::Rotate(int nPosX, int nPosY, int nCurrentRotation)
{
	switch (nCurrentRotation % 4)
	{
	case 0:
		return nPosY * 4 + nPosX;			//0 degree rotation

	case 1:
		return 12 + nPosY - (nPosX * 4);	//90 degree rotation

	case 2:
		return 15 - (nPosY * 4) - nPosX;	//180 degree rotation

	case 3:
		return 3 - nPosY + (nPosX * 4);		//270 degree rotation
	}
}

Tetromino::~Tetromino()
{
	delete[] pTetromino;
}