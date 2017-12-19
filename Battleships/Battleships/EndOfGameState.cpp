#include "EndOfGameState.h"



EndOfGameState::EndOfGameState(class Battleships * context)
{
	this->context = context;
}


EndOfGameState::~EndOfGameState()
{
}

void EndOfGameState::doJob()
{
	int playerOneSunkShips = this->context->getPlayerOne()->getNumberOfSunkShips();
	int playerTwoSunkShips = this->context->getPlayerTwo()->getNumberOfSunkShips();
	int timeOfGame = (clock() - this->context->getStartTime()) / CLOCKS_PER_SEC;

	
	
	setCursorPosition(0, battleships::USER_INPUT_ROW - 3);
	if (battleships::NUMBER_OF_SHIPS == playerOneSunkShips)
	{
		std::cout << "You lost :(                " << std::endl;
	}
	else
	{
		std::cout << "You won! Congratulations!  " << std::endl;
	}

	std::cout << std::endl;
	std::cout << "You sunk " << playerTwoSunkShips  << " of enemy's ships                      "<< std::endl;
	std::cout << "Enemy sunk " << playerOneSunkShips << " of your ships" << std::endl;
	std::cout << "Time: " << timeOfGame << " seconds" << std::endl;
	std::cout << std::endl;
	std::cout << "Press ENTER to exit..." << std::endl;

	char keyPressed = 0;
	const char ENTER_KEY = '\r';

	while (ENTER_KEY != keyPressed)
	{
		keyPressed = _getch();
	}

	exit(0);
}

void EndOfGameState::setCursorPosition(int column, int row) const
{
	COORD coord;
	coord.X = column;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}