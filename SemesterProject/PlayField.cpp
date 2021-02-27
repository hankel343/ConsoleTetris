#include "PlayField.h"

PlayField::PlayField()
{
	pField = new unsigned char[nFieldWidth * nFieldHeight];
	for (int x = 0; x < nFieldWidth; x++)
		for (int y = 0; y < nFieldHeight; y++)
			pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;
}

int PlayField::GetFieldWidth() const
{
	return nFieldWidth;
}

int PlayField::GetFieldHeight() const
{
	return nFieldHeight;
}

bool PlayField::IsValidMovement(int nCurrentPiece, int nCurrentRotation, int nPosX, int nPosY)
{



	return true;
}

PlayField::~PlayField()
{
	delete[] pField;
}