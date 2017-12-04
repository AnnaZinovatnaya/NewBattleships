#ifndef SRC_SHIP_H_
#define SRC_SHIP_H_

#include "BattleshipsHelper.h"

class Ship
{
public:
	Ship();
	Ship(int x, int y, int size, bool  isHorizontal);
	~Ship();

	bool isSunkCheck(int enemyHits[battleships::FIELD_SIZE][battleships::FIELD_SIZE]) const;
	bool isShipCoordinates(int hitX, int hitY) const;

	bool getIsSunk() const { return isSunk; }
	void setIsSunk(bool newStatus) { isSunk = newStatus; }

	int getX() const { return x; }

	int getY() const { return y; }

	bool getIsHorizontal() const { return isHorizontal; }

	int getSize() const { return size; }


private:
	int x;
	int y;
	int size;
	bool isHorizontal;
	bool isSunk;
};

#endif /* SRC_SHIP_H_ */
