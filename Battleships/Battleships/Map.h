#ifndef SRC_MAP_H_
#define SRC_MAP_H_

#include <vector>
#include <iostream>

#include <Windows.h>

#include "BattleshipsHelper.h"

class Map {
public:
	Map(std::vector<std::vector<int> > field1);
	~Map();

	void draw();
	void notifyOnMove(int player, int x, int y, bool success);
protected:
private:
	static const int  VERTICAL_SIZE = 13, HORIZONTAL_SIZE = 49;

	std::vector<std::vector<char> > map;
};

#endif /* SRC_MAP_H_ */