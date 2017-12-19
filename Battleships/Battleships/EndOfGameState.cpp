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

	
	
	battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW - 3);
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
	std::cout << std::endl;

	int minutes = static_cast<int>(timeOfGame / 60);
	std::cout << "Time: " << minutes << " minute(s) ";
	std::cout << timeOfGame - (minutes * 60) << " second(s)" << std::endl;

	std::cout << std::endl;
	std::cout << "Press ENTER to exit..." << std::endl;

	battleships::Helper::waitForEnterPressed();

	exit(0);
}