#include <iostream>
#include "Board.h"



int main()
{
	Board newBoard;
	int gameMode = 0;

	do
	{

		cout << "Please, choose your game mode(1 - Against AI | 2 - Duel)" << endl;
		cin >> gameMode;

	} while (gameMode != 1 && gameMode != 2);

	switch (gameMode)
	{
	case AI:
		newBoard.PlayAgainstEngine();
		break;

	case DUEL:
		newBoard.PlayAgainstHuman();
		break;

	default:
		cout << "Gamemode Input Error." << endl;
	}

	return 0;

}

