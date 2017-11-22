#include "Battleships.h"

Battleships::Battleships() {
	player1 = new Player();
	//player2 = new ComputerPlayer();
	player2 = new Player();
	map = new Map(player1->getField());
	startTime = 0;
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

	bool endOfGame = false;

	while (!endOfGame) {
		int x = 0;
		int y = 0;

		player1->makeMove(x, y);

		switch (player2->checkMove(x, y)) {
		case battleships::playerState::INJURED:
			player1->notifyOnInjured();
			map->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::SUCCESS);
			break;
		case battleships::playerState::SUNK:
			player1->notifyOnSunk();
			map->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::SUCCESS);
			break;
		case battleships::playerState::DEFEATED:
			map->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::SUCCESS);
			endOfGame = true;
			break;
		default:
			map->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::MISS);
			break;
		}

		player2->makeMove(x, y);

		switch (player1->checkMove(x, y)) {
		case battleships::playerState::INJURED:
			player2->notifyOnInjured();
			map->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::SUCCESS);
			break;
		case battleships::playerState::SUNK:
			player2->notifyOnSunk();
			map->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::SUCCESS);
			break;
		case battleships::playerState::DEFEATED:
			map->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::SUCCESS);
			endOfGame = true;
			break;
		default:
			map->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::MISS);
			break;
		}
	}

	showResult();
}

void Battleships::pause() {

}

void Battleships::resume() {

}

void Battleships::showResult() {

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
}