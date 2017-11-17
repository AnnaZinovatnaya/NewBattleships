/*
 * Battleships.h
 *
 *  Created on: Nov 17, 2017
 *      Author: HZinovatna
 */

#ifndef SRC_BATTLESHIPS_H_
#define SRC_BATTLESHIPS_H_

#include <ctime>
#include <conio.h>
#include <iostream>

#include "Player.h"
#include "ComputerPlayer.h"
#include "Map.h"
#include "BattleshipsHelper.h"

class Battleships {
public:
	Battleships();
	~Battleships();

	void play();
protected:
private:

	Map * map;
	Player * player1;
	Player * player2;

	clock_t startTime;

	void pause();
	void resume();
	void showResult();

	int getCurrentTimeInSec();

	void waitForEnterPressed() const;

	void printWelcomeMessage();
};

#endif /* SRC_BATTLESHIPS_H_ */
