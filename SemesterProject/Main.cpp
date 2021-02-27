#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
	Board GameBoard;
	PlayField PlayField;

	//Game Logic:
	bool bGameOver = false;

	while (bGameOver == false)
	{

		
		GameBoard.UpdateScreen(PlayField);

		//Display Frame:
		GameBoard.DisplayFrame();
	}



	return 0;
}