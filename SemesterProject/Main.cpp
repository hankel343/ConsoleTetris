#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
	srand(time(0));
	Board GameBoard;
	PlayField PlayField;
	Tetromino Pieces;

	//Game Logic:
	bool bGameOver = false;

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