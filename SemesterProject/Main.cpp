#include <iostream>
#include <thread>
#include "Board.h"

using namespace std;

int main()
{
	srand(time(0)); //Used for random piece generation

	//Creating Game Objects:
	Board GameBoard;
	PlayField PlayField;
	Tetromino Pieces;

	//Game Logic:
	bool bGameOver = false;
	bool bKey[4];
	bool bRotateHold = true;
	Pieces.GetNewPiece(); //Get an initial piece for the first iteration.

	//Game Loop:
	while (bGameOver == false)
	{
		/*=========== TIMING ===========*/
		this_thread::sleep_for(100ms);

		/*========= PLAYER INPUT ==========*/
		for (int i = 0; i < 4; i++)	//Uses virtual key codes for left, right, down, and 'z' keys
			bKey[i] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[i]))) != 0;
		//Stores T in the array if the key is being pressed. False otherwise.

		if (bKey[1]) //Left
		{
			if (PlayField.IsValidMovement(Pieces, Pieces.nCurrentRotation, Pieces.nCurrentX-1, Pieces.nCurrentY))
				Pieces.nCurrentX = Pieces.nCurrentX - 1;
		}

		if (bKey[0]) //Right
		{
			if (PlayField.IsValidMovement(Pieces, Pieces.nCurrentRotation, Pieces.nCurrentX + 1, Pieces.nCurrentY))
				Pieces.nCurrentX = Pieces.nCurrentX + 1;
		}

		if (bKey[2]) //Down
		{
			if (PlayField.IsValidMovement(Pieces, Pieces.nCurrentRotation, Pieces.nCurrentX, Pieces.nCurrentY + 1))
				Pieces.nCurrentY = Pieces.nCurrentY + 1;
		}

		if (bKey[3]) //Z
		{
			if (PlayField.IsValidMovement(Pieces, Pieces.nCurrentRotation + 1, Pieces.nCurrentX, Pieces.nCurrentY))
			{
				Pieces.nCurrentRotation = Pieces.nCurrentRotation + 1;
				bRotateHold = false;
			}
		}
		else
			bRotateHold = true;

		/*========= RENDER OUTPUT =========*/
		GameBoard.UpdateScreen(PlayField);
		GameBoard.DrawPiece(Pieces);

		//Display Frame:
		GameBoard.DisplayFrame();
	}



	return 0;
}