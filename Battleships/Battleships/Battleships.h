#ifndef SRC_BATTLESHIPS_H_
#define SRC_BATTLESHIPS_H_

#include <ctime>
#include <conio.h>
#include <iostream>

#include "BattleshipsHelper.h"
#include "ComputerPlayer.h"
#include "Map.h"
#include "Player.h"
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

	void returnPreviousState();
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

	void printWelcomeMessage() const;
};

#endif /* SRC_BATTLESHIPS_H_ */
