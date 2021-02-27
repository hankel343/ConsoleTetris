#ifndef PLAYFIELD_H
#define PLAYFIELD_H

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
	int RotatePiece(int nPosX, int nPosY, int rotation);
	int GetFieldWidth() const;
	int GetFieldHeight() const;
	bool IsValidMovement(int nCurrentPiece, int nCurrentRotation, int nPosX, int nPosY);

	//Destructor:
	~PlayField();
};

#endif PLAYFIELD_H