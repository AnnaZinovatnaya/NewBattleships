#include "Player.h"

Player::Player() {
	std::vector<int> row(10, '0');
	std::vector<std::vector<int> > field(10, row);

	this->field = field;
}

Player::~Player() {
}

void Player::makeMove(int & x, int & y) {
	x = rand() % 10;
	y = rand() % 10;
}

std::vector<std::vector<int> > Player::getField() {
	return field;
}

void Player::notifyOnInjured() {

}

void Player::notifyOnSunk() {

}

int Player::checkMove(int x, int y) {
	return 0;
}