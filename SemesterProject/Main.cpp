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
	bool bRotateHold = true; //Used to prevent rotation of the piece from happening too fast.
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

		if (bKey[0]) //Right
			PlayField.ProcessKeyPress(0, Pieces);
		if (bKey[1]) //Left
			PlayField.ProcessKeyPress(1, Pieces);
		if (bKey[2]) //Down
			PlayField.ProcessKeyPress(2, Pieces);
		if (bKey[3]) //Rotate
		{
			PlayField.ProcessKeyPress(3, Pieces);
			bRotateHold = false;
		} else
			bRotateHold = true;

		/*========= RENDER OUTPUT =========*/
		GameBoard.UpdateScreen(PlayField);
		GameBoard.DrawPiece(Pieces);

		//Display Frame:
		GameBoard.DisplayFrame();
	}



	return 0;
}