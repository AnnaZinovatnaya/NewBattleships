#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer() {
	std::vector<int> row(battleships::FIELD_SIZE, 0);
	std::vector<std::vector<int> > moves(battleships::FIELD_SIZE, row);

	this->moves = moves;

}

ComputerPlayer::~ComputerPlayer() {
}

void ComputerPlayer::makeMove(int & x, int & y) {
	x = rand() % battleships::FIELD_SIZE;
	y = rand() % battleships::FIELD_SIZE;

	while (1 == moves[x][y])
	{
		x = rand() % battleships::FIELD_SIZE;
		y = rand() % battleships::FIELD_SIZE;
	}

	moves[x][y] = 1;
}