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

	std::cout << std::endl;
	std::cout << "You sunk " << playerTwoSunkShips  << " of enemy's ships"<< std::endl;
	std::cout << "Enemy sunk " << playerOneSunkShips << " of your ships" << std::endl;
	std::cout << "Time: " << timeOfGame << " seconds" << std::endl;
	std::cout << std::endl;
}
