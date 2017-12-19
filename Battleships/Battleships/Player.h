#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

#include <cstdlib>
#include <vector>
#include <conio.h>
#include <iostream>
#include <Windows.h>

#include "BattleshipsHelper.h"
#include "Ship.h"

class Player {
public:
	Player();
	~Player();

	virtual void makeMove(int & x, int & y);
	std::vector<std::vector<int> > getField();

	void notifyOnInjured();
	void notifyOnSunk();
	int checkMove(int x, int y);

	void setInput(char letter, char digit);

	int getNumberOfSunkShips();

protected:
private:
	std::vector<std::vector<int> > field;
	std::vector<std::vector<int> > enemyMoves;
	std::vector<Ship> fleet;

	int numberOfSunkShips;

	char lastLetter;
	char lastDigit;

	void generateShips();
	void generateShip(const int size);
	bool checkPlace(int x, int y, bool isHorizontal, int size);
	void setCursorPosition(int column, int row) const;
	bool isAnyShipSunk(int x, int y) const;
};

#endif /* SRC_PLAYER_H_ */