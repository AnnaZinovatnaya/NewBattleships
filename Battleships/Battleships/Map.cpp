#include "Map.h"

Map::Map(std::vector<std::vector<int> > field1) {
	char tempMap[VERTICAL_SIZE][HORIZONTAL_SIZE] = {
		"   0123456789     0123456789 ",
		"  #----------#   #----------#",
		" A|          |  A|          |",
		" B|          |  B|          |",
		" C|          |  C|          |",
		" D|          |  D|          |",
		" E|          |  E|          |",
		" F|          |  F|          |",
		" G|          |  G|          |",
		" H|          |  H|          |",
		" I|          |  I|          |",
		" J|          |  J|          |",
		"  #----------#   #----------#"
	};

	std::vector<char> row(HORIZONTAL_SIZE, '0');
	std::vector<std::vector<char> > map(VERTICAL_SIZE, row);

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++)
			map[i][j] = tempMap[i][j];
	}

	this->map = map;

	for (int i = 0; i < field1.size(); i++) {
		for (int j = 0; j < field1[i].size(); j++)
			if (1 == field1[i][j])
				map[i + 3][j + 3] = 'S';
	}
}

Map::~Map() {
}

void Map::draw() {
	system("cls");

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++)
			std::cout << map[i][j];
		std::cout << std::endl;
	}

	std::cout << "\n";
	std::cout << "Press 'p' to pause the game";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Type character and digit and press ENTER to hit:\n";
}

void Map::notifyOnMove(int player, int x, int y, bool success) {

}