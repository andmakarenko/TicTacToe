#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class Board {
private:
	vector<int> fields;
	int userType;

	void printBoard();
	void setUserType(int _userType);
	int getUserType();
	bool checkField(int field);
	int fieldInput();
	int fieldInputEngine();
	void TicField(int field);
	void TacField(int field);
	bool TicWon();
	bool TacWon();
	bool Draw();
	void setBoardZero();

public:
	Board() :
		fields(9, 0),
		userType(0)
	{}

	void PlayAgainstEngine();
	void PlayAgainstHuman();

};
enum USERTYPE { TIC = 1, TAC };
enum GAMEMODE { AI = 1, DUEL};