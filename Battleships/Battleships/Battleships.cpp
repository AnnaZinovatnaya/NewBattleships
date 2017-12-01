#include "Battleships.h"

Battleships::Battleships() {
	srand(time(0));

	player1 = new Player();
	player2 = new ComputerPlayer();
	map = new Map(player1->getField());
	startTime = 0;
	currentState = new WaitForInputState(this);
	previousState = NULL;
}

Battleships::~Battleships() {
	if (0 != player1) {
		delete player1;
	}

	if (0 != player2) {
		delete player1;
	}

	if (0 != map) {
		delete player1;
	}
}

void Battleships::play() {

	printWelcomeMessage();

	waitForEnterPressed();

	map->draw();

	startTime = clock();

	currentState->doJob();
}

int Battleships::getCurrentTimeInSec() {
	return static_cast<int>(clock() - startTime) / CLOCKS_PER_SEC;
}

void Battleships::waitForEnterPressed() const
{
	char keyPressed = 0;
	const char ENTER_KEY = '\r';

	while (ENTER_KEY != keyPressed)
	{
		keyPressed = _getch();
	}
}

void Battleships::printWelcomeMessage() {
	std::cout << "\n";
	std::cout << " *************************************" << std::endl;
	std::cout << " *                                   *" << std::endl;
	std::cout << " *      Welcome to BATTLESHIPS!      *" << std::endl;
	std::cout << " *                                   *" << std::endl;
	std::cout << " *************************************" << std::endl;
	std::cout << "\n\n";
	std::cout << " Press ENTER to start...";
	std::cout << std::endl;
}

void Battleships::changeState(State * newState)
{
	delete previousState;

	previousState = currentState;
	currentState = newState;
	currentState->doJob();
}

Player * Battleships::getPlayerOne()
{
	return player1;
}

Map * Battleships::getMap()
{
	return map;
}

Player * Battleships::getPlayerTwo()
{
	return player2;
}

clock_t Battleships::getStartTime()
{
	return startTime;
}