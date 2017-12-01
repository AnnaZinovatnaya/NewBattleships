#ifndef SRC_BATTLESHIPS_H_
#define SRC_BATTLESHIPS_H_

#include <ctime>
#include <conio.h>
#include <iostream>

#include "Player.h"
#include "ComputerPlayer.h"
#include "Map.h"
#include "BattleshipsHelper.h"
#include "State.h"
#include "WaitForInputState.h"

class Battleships {
public:
	Battleships();
	~Battleships();

	void play();

	void changeState(State * newState);

	Player * getPlayerOne();
	Player * getPlayerTwo();
	Map * getMap();

	clock_t getStartTime();
protected:
private:

	Map * map;
	Player * player1;
	Player * player2;

	clock_t startTime;

	State * currentState;
	State * previousState;

	int getCurrentTimeInSec();

	void waitForEnterPressed() const;

	void printWelcomeMessage();
};

#endif /* SRC_BATTLESHIPS_H_ */
