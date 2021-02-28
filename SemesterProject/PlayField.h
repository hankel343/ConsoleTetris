#pragma once
#include <string>
#include "Tetromino.h"

class PlayField
{
private:
	int nFieldWidth = 12;
	int nFieldHeight = 18;

public:
	//Attribute:
	unsigned char* pField;

	//Constructor:
	PlayField();

	//Methods:
	int GetFieldWidth() const;
	int GetFieldHeight() const;
	bool IsValidMovement(Tetromino& FallingPiece, int nCurrentRotation, int nPosX, int nPosY);
	void LockPiece(Tetromino& FallingPiece);
	void ProcessKeyPress(int nDirection, Tetromino& FallingPiece);

	//Destructor:
	~PlayField();
};