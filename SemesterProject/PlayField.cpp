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

bool PlayField::IsValidMovement(Tetromino& FallingPiece, int nCurrentRotation, int nPosX, int nPosY)
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			//Gets the index of a single array cell where that cell WILL be if this function returns true.
			int nPieceIndex = FallingPiece.Rotate(x, y, nCurrentRotation);

			//This translates the 4x4 tetromino array to the playfield array.
			int nFieldIndex = (nPosY + y) * nFieldWidth + (nPosX + x);

			//Following two ifs are simply checking to see that the piece is withint bounds:
			if (nPosX + x >= 0 && nPosX + x < nFieldWidth)
			{
				if (nPosY + y >= 0 && nPosY + y < nFieldHeight)
				{
					//If the rotated tetromino index has an 'X' in the same location that there is a non-zero value in the playfield, this is invalid movement.
					if (FallingPiece.pTetromino[FallingPiece.nCurrentPiece][nPieceIndex] == L'X' && pField[nFieldIndex] != 0)
						return false; //Returns false the first time that a collision is detected.
				}
			}
		}


	return true; //Returns true if all array indexes are checked and found to have no collisions. 
}

void PlayField::ProcessKeyPress(int nDirection, Tetromino& Piece)
{
	switch (nDirection)
	{
	case 0:
		if (IsValidMovement(Piece, Piece.nCurrentRotation, Piece.nCurrentX + 1, Piece.nCurrentY))
			Piece.nCurrentX = Piece.nCurrentX + 1;
		break;

	case 1:
		if (IsValidMovement(Piece, Piece.nCurrentRotation, Piece.nCurrentX - 1, Piece.nCurrentY))
			Piece.nCurrentX = Piece.nCurrentX - 1;
		break;

	case 2:
		if (IsValidMovement(Piece, Piece.nCurrentRotation, Piece.nCurrentX, Piece.nCurrentY + 1))
			Piece.nCurrentY = Piece.nCurrentY + 1;
		break;

	case 3:
		if (IsValidMovement(Piece, Piece.nCurrentRotation+1, Piece.nCurrentX, Piece.nCurrentY))
			Piece.nCurrentRotation = Piece.nCurrentRotation + 1;
		break;
	}
}

PlayField::~PlayField()
{
	delete[] pField;
}