#ifndef SRC_SHIP_H_
#define SRC_SHIP_H_

#include "BattleshipsHelper.h"

class Ship
{
public:
	Ship(int x, int y, int size, bool  isHorizontal);
	~Ship();

	bool isShipCoordinates(int hitX, int hitY) const;

	bool isSunk() const;
	void increaseSuccessfulHits();


private:
	int x;
	int y;
	int size;
	bool isHorizontal;
	int successfulHits;
};

#endif /* SRC_SHIP_H_ */
