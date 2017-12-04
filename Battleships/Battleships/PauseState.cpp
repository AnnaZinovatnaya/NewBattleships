#include "PauseState.h"



PauseState::PauseState(Battleships * context)
{
	this->context = context;
}


PauseState::~PauseState()
{
}

void PauseState::doJob()
{
	setCursorPosition(0, battleships::USER_INPUT_ROW);
	std::cout << " ";
	setCursorPosition(0, battleships::USER_INPUT_ROW + 1);
	std::cout << "PAUSE" << std::endl;
	std::cout << "Press ENTER to continue";

	char keyPressed = 0;
	const char ENTER_KEY = '\r';

	while (ENTER_KEY != keyPressed)
	{
		keyPressed = _getch();
	}

	setCursorPosition(0, battleships::USER_INPUT_ROW + 1);
	std::cout << "     ";
	setCursorPosition(0, battleships::USER_INPUT_ROW + 2);
	std::cout << "                       ";
	setCursorPosition(0, battleships::USER_INPUT_ROW);
	this->context->returnPreviousState();
}

void PauseState::setCursorPosition(int column, int row) const
{
	COORD coord;
	coord.X = column;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}