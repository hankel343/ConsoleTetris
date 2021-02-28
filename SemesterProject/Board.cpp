#include "Board.h"
#include <Windows.h>
#define SCREEN_OFFSET 2

Board::Board()
{
	pScreen = new wchar_t[nScreenWidth * nScreenHeight];
	for (int i = 0; i < nScreenWidth * nScreenHeight; i++)
		pScreen[i] = L' ';

	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
}

void Board::UpdateScreen(PlayField& PlayFieldObj)
{
	int nFieldWidth = PlayFieldObj.GetFieldWidth();
	int nFieldHeight = PlayFieldObj.GetFieldHeight();

	for (int x = 0; x < nFieldWidth; x++)
		for (int y = 0; y < nFieldHeight; y++)
		{
			pScreen[(y + SCREEN_OFFSET) * nScreenWidth + (x + SCREEN_OFFSET)] = " ABCDEFG=#"[PlayFieldObj.pField[y * nFieldWidth + x]];
		}
			
}

void Board::DrawPiece(Tetromino& FallingPiece)
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			if (FallingPiece.pTetromino[FallingPiece.nCurrentPiece][FallingPiece.Rotate(x, y, FallingPiece.nCurrentRotation)] == L'X') {
				pScreen[(FallingPiece.nCurrentY + y + SCREEN_OFFSET) * nScreenWidth + (FallingPiece.nCurrentX + x + SCREEN_OFFSET)] = char(FallingPiece.nCurrentPiece + 65);
			}

}

void Board::DisplayFrame()
{
	WriteConsoleOutputCharacter(hConsole, pScreen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
	
}

Board::~Board()
{
	delete[] pScreen;
}