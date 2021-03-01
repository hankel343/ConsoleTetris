#pragma once
#include <Windows.h>
#include "PlayField.h"
#include "Tetromino.h"

class Board
{
private:
	int nScreenWidth = 80;
	int nScreenHeight = 30;
	HANDLE hConsole;
	DWORD dwBytesWritten;


public:
	//Attributes:
	wchar_t* pScreen;

	//Constructor:
	Board();

	//Methods:
	void UpdateScreen(PlayField& PlayFieldObj);
	void DrawPiece(Tetromino& FallingPiece);
	void DisplayFrame();
	HANDLE GetHandle();

	//Destructor:
	~Board();
};