#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

#include <cstdlib>
#include <vector>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <Windows.h>

#include "BattleshipsHelper.h"

class Player {
public:
	Player();
	~Player();

	virtual void makeMove(int & x, int & y);
	std::vector<std::vector<int> > getField();

	void notifyOnInjured();
	void notifyOnSunk();
	int checkMove(int x, int y);
protected:
	//------------------------------------
	std::ofstream myfile;
	//------------------------------------
private:
	std::vector<std::vector<int> > field;

	void generateShips();
	void generateShip(const int size);
	bool checkPlace(int x, int y, bool isHorizontal, int size);
	void setCursorPosition(int column, int row) const;
};

#endif /* SRC_PLAYER_H_ */