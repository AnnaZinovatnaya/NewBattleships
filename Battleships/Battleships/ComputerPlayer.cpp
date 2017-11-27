#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer() {
	// TODO Auto-generated constructor stub

}

ComputerPlayer::~ComputerPlayer() {
	// TODO Auto-generated destructor stub
}

void ComputerPlayer::makeMove(int & x, int & y) {
	x = rand() % 10;
	y = rand() % 10;

	Player::myfile << "Computer hit: " << x << " " << y << "\n";
}