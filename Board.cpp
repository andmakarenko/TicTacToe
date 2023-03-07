#include "Board.h"

void Board::printBoard()
{
	cout << "_______" << endl;


	for (int j = 0; j < 3; j++)

	{
		cout << "|";
		for (int i = 0; i < 3; i++)
		{
			if (fields[i + 3*j] == 1)
			{
				cout << "X|";
			}
			else if (fields[i + 3*j] == 2)
			{
				cout << "O|";
			}
			else
			{
				cout << " |";
			}
		}
		cout << endl;
		cout << "-------" << endl;
	}
};


void Board::setUserType(int _userType)
{
	userType = _userType;
}

int Board::getUserType()
{
	return userType;
}

bool Board::checkField(int field)
{
	if (fields[static_cast<std::vector<int, std::allocator<int>>::size_type>(field) - 1] != 0)
	{
		cout << "This field is already occupied." << endl;
		return false;
	}
	return true;
}

int Board::fieldInput()
{
	int fieldOut;

	do {
		cout << "Please input the field to place on: ";
		cin >> fieldOut;
	} while ((fieldOut < 1 || fieldOut > 9) || !checkField(fieldOut));

	return fieldOut;
}

int Board::fieldInputEngine()
{
	srand(time(NULL));
	vector<int> index;

	for (int i = 0; i < 9; i++)
	{
		if (fields[i] == 0)
		{
			index.push_back(i);
		}
	}

	return index[rand() % index.size()] + 1;
}

void Board::TicField(int field)
{
	if (fields[static_cast<std::vector<int, std::allocator<int>>::size_type>(field) - 1] != 0)
	{
		cout << "Cant put a tic there!" << endl;
		return;
	}

	fields[static_cast<std::vector<int, std::allocator<int>>::size_type>(field) - 1] = 1;
}

void Board::TacField(int field)
{

	if (fields[static_cast<std::vector<int, std::allocator<int>>::size_type>(field) - 1] != 0)
	{
		cout << "Cant put a tac there!" << endl;
		return;
	}

	fields[static_cast<std::vector<int, std::allocator<int>>::size_type>(field) - 1] = 2;
}


bool Board::TicWon()
{
	if (fields[0] == 1 && fields[1] == 1 && fields[2] == 1)
	{
		cout << "Tic Won!" << endl;
		return true;
	}
	if (fields[3] == 1 && fields[4] == 1 && fields[5] == 1)
	{
		cout << "Tic Won!" << endl;
		return true;
	}
	if (fields[6] == 1 && fields[7] == 1 && fields[8] == 1)
	{
		cout << "Tic Won!" << endl;
		return true;
	}
	if (fields[0] == 1 && fields[3] == 1 && fields[6] == 1)
	{
		cout << "Tic Won!" << endl;
		return true;
	}
	if (fields[1] == 1 && fields[4] == 1 && fields[7] == 1)
	{
		cout << "Tic Won!" << endl;
		return true;
	}
	if (fields[2] == 1 && fields[5] == 1 && fields[8] == 1)
	{
		cout << "Tic Won!" << endl;
		return true;
	}
	if (fields[0] == 1 && fields[4] == 1 && fields[8] == 1)
	{
		cout << "Tic Won!" << endl;
		return true;
	}
	if (fields[2] == 1 && fields[4] == 1 && fields[6] == 1)
	{
		cout << "Tic Won!" << endl;
		return true;
	}

	return false;
}


bool Board::TacWon()
{
	if (fields[0] == 2 && fields[1] == 2 && fields[2] == 2)
	{
		cout << "Tac Won!" << endl;
		return true;
	}
	if (fields[3] == 2 && fields[4] == 2 && fields[5] == 2)
	{
		cout << "Tac Won!" << endl;
		return true;
	}
	if (fields[6] == 2 && fields[7] == 2 && fields[8] == 2)
	{
		cout << "Tac Won!" << endl;
		return true;
	}
	if (fields[0] == 2 && fields[3] == 2 && fields[6] == 2)
	{
		cout << "Tac Won!" << endl;
		return true;
	}
	if (fields[1] == 2 && fields[4] == 2 && fields[7] == 2)
	{
		cout << "Tac Won!" << endl;
		return true;
	}
	if (fields[2] == 2 && fields[5] == 2 && fields[8] == 2)
	{
		cout << "Tac Won!" << endl;
		return true;
	}
	if (fields[0] == 2 && fields[4] == 2 && fields[8] == 2)
	{
		cout << "Tac Won!" << endl;
		return true;
	}
	if (fields[2] == 2 && fields[4] == 2 && fields[6] == 2)
	{
		cout << "Tac Won!" << endl;
		return true;
	}

	return false;
}


bool Board::Draw()
{
	for (int i = 0; i < 9; i++)
	{
		if (fields[i] == 0)
		{
			return false;
		}
	}

	cout << "Draw." << endl;
	return true;
}


void Board::setBoardZero()
{
	for (int i = 0; i < 9; i++)
	{
		fields[i] = 0;
	}
}

void Board::PlayAgainstEngine()
{
	cout << "Welcome to the Tic Tac Toe game!(Single Player)" << endl;

	int _userType;

	int answer = 1;

	while (answer != 2)
	{
		do {
			cout << "Please, enter 1 for TIC, 2 for TAC: ";
			cin >> _userType;
		} while (_userType != TIC && _userType != TAC);

		setUserType(_userType);

		switch (getUserType())
		{
		case TIC:
			printBoard();
			while (!Draw() && !TicWon() && !TacWon())
			{
				TicField(fieldInput());
				printBoard();
				if (Draw() || TicWon())
				{
					break;
				}
				TacField(fieldInputEngine());
				printBoard();
			}
			break;

		case TAC:
			printBoard();
			while (!Draw() && !TicWon() && !TacWon())
			{
				TicField(fieldInputEngine());
				printBoard();
				if (Draw() || TicWon())
				{
					break;
				}
				TacField(fieldInput());
				printBoard();
			}
			break;

		default:
			cout << "User Type Input Error." << endl;
			return;

		}

		setBoardZero();

		cout << "Want to play again?(1 - OK, 2 - Cancel)" << endl;
		cin >> answer;
	}
}


void Board::PlayAgainstHuman()
{
	cout << "Welcome to the Tic Tac Toe game!(Duel)" << endl;

	int _userType;

	int answer = 1;

	while (answer != 2)
	{
		do {
			cout << "Player1, enter 1 for TIC, 2 for TAC: ";
			cin >> _userType;
		} while (_userType != TIC && _userType != TAC);

		setUserType(_userType);


		switch (getUserType())
		{
		case TIC:
			cout << "Player1: TIC" << endl;
			cout << "Player2: TAC" << endl;
			break;

		case TAC:
			cout << "Player1: TAC" << endl;
			cout << "Player2: TIC" << endl;
			break;

		default:
			cout << "User Type Input Error." << endl;
			return;

		}


		printBoard();
		while (!Draw() && !TicWon() && !TacWon())
		{
			TicField(fieldInput());
			printBoard();
			if (Draw() || TicWon())
			{
				break;
			}

			TacField(fieldInput());
			printBoard();
		}



		setBoardZero();

		cout << "Want to play again?(1 - OK, 2 - Cancel)" << endl;
		cin >> answer;
	}
}

