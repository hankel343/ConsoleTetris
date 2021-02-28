#include <thread>
#include <vector>
#include "Board.h"

using namespace std;

int main()
{
	srand(time(0)); //Used for random piece generation

	//Creating Game Objects:
	Board GameBoard;
	PlayField PlayField;
	Tetromino FallingBlock;

	//Game Logic:
	bool bGameOver = false;
	bool bKey[4];
	bool bRotateHold = true; //Used to prevent rotation of the piece from happening too fast.
	int nSpeed = 20;
	int nSpeedCounter = 0;
	bool bForceDown = false;
	vector<int> vRemovedLines;
	FallingBlock.GetNewPiece(); //Get an initial piece for the first iteration.
	
	//Game Loop:
	while (bGameOver == false)
	{
		/*=========== TIMING ===========*/
		this_thread::sleep_for(100ms);
		nSpeedCounter++;
		bForceDown = (nSpeedCounter == nSpeed); //Once nSpeedCounter has accumulated enough ticks to be eq. to nSpeed, the shape is automatically forced down.

		/*========= PLAYER INPUT ==========*/
		for (int i = 0; i < 4; i++)	//Uses virtual key codes for left, right, down, and 'z' keys
			bKey[i] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[i]))) != 0;
		//Stores T in the array if the key is being pressed. False otherwise.

		/*=========== GAME LOGIC ===========*/
		if (bKey[0]) //Right
			PlayField.ProcessKeyPress(0, FallingBlock);
		if (bKey[1]) //Left
			PlayField.ProcessKeyPress(1, FallingBlock);
		if (bKey[2]) //Down
			PlayField.ProcessKeyPress(2, FallingBlock);
		if (bKey[3]) //Rotate
		{
			PlayField.ProcessKeyPress(3, FallingBlock);
			bRotateHold = false; //If the user is pressing 'z', this will be set to false which will prevent the piece from spinning at the frame rate. 
		} else
			bRotateHold = true;

		if (bForceDown) //Appropriate amount of time has elapsed for the falling block to be forced down the screen.
		{
			if (PlayField.IsValidMovement(FallingBlock, FallingBlock.nCurrentRotation, FallingBlock.nCurrentX, FallingBlock.nCurrentY + 1))
				FallingBlock.nCurrentY++; //If the piece can fit farther down, then push the piece farther down the screen.
			else
			{
				//Lock into play field:
				PlayField.LockPiece(FallingBlock);

				//Check if any lines are formed:
				PlayField.CheckForLines(FallingBlock, vRemovedLines);

				//Get next piece:
				FallingBlock.GetNewPiece();

				//If new block does not fit, then the game is over:
				bGameOver = (PlayField.IsValidMovement(FallingBlock, FallingBlock.nCurrentRotation, FallingBlock.nCurrentX, FallingBlock.nCurrentY) == false);
			}
			
			nSpeedCounter = 0;
		}

		/*========= RENDER OUTPUT =========*/
		GameBoard.UpdateScreen(PlayField);
		GameBoard.DrawPiece(FallingBlock);

		//Display Frame:
		if (!(vRemovedLines.empty())) //If some lines have been removed from the play field
		{
			GameBoard.DisplayFrame();
			this_thread::sleep_for(100ms); //Adds a delay so the player can see that they completed a line.
			PlayField.MoveCompletedLineDown(vRemovedLines);
		} else
			GameBoard.DisplayFrame();
	}

	return 0;
}