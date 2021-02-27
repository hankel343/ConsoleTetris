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
			pScreen[(y + SCREEN_OFFSET) * nScreenWidth + (x + SCREEN_OFFSET)] = " ABCDEFG=#"[PlayFieldObj.pField[y * nFieldWidth + x]];
}

void Board::DisplayFrame()
{
	WriteConsoleOutputCharacter(hConsole, pScreen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
}

Board::~Board()
{
	delete[] pScreen;
}