#include "Ship.h"

Ship::Ship(int x, int y, int size, bool isHorizontal)
{
	this->x = x;
	this->y = y;
	this->size = size;
	this->isHorizontal = isHorizontal;
	this->successfulHits = 0;
}

Ship::~Ship()
{
}

bool Ship::isSunk() const
{
	return successfulHits == size;
}

bool Ship::isShipCoordinates(int hitX, int hitY) const
{
	if (isHorizontal)
	{
		for (int i = y; i < y + size; i++)
		{
			if (x == hitX && i == hitY)
			{
				return true;
			}
		}
	}
	else
	{
		for (int i = x; i < x + size; i++)
		{
			if (i == hitX && y == hitY)
			{
				return true;
			}
		}
	}

	return false;
}

void Ship::increaseSuccessfulHits()
{
	++successfulHits;
}