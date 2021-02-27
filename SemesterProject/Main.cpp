#include <iostream>
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
	Pieces.GetNewPiece(); //Get an initial piece for the first iteration.

	//Game Loop:
	while (bGameOver == false)
	{

		
		/*========= Render Output =========*/
		GameBoard.UpdateScreen(PlayField);
		GameBoard.DrawPiece(Pieces);

		//Display Frame:
		GameBoard.DisplayFrame();
	}



	return 0;
}