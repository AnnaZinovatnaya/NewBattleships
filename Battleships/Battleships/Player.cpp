#include "Player.h"

Player::Player() {
	std::vector<int> row(battleships::FIELD_SIZE, 0);
	std::vector<std::vector<int> > field(battleships::FIELD_SIZE, row);

	this->field = field;

	std::vector<std::vector<int> > enemyMoves(battleships::FIELD_SIZE, row);

	this->enemyMoves = enemyMoves;

	lastLetter = ' ';
	lastDigit = ' ';

	numberOfSunkShips = 0;

	generateShips();
}

Player::~Player() {
}

void Player::makeMove(int & x, int & y) {

	if (lastLetter >= 'A' && lastLetter <= 'J')
	{
		x = lastLetter % 'A';
	}
	else
	{
		x = lastLetter % 'a';
	}

	y = lastDigit % '0';

}

std::vector<std::vector<int> > Player::getField() {
	return field;
}

void Player::notifyOnInjured() {

}

void Player::notifyOnSunk() {

}

int Player::checkMove(int x, int y) {
	if (1 == field[x][y])
	{
		if(isAnyShipSunk(x, y)) {
			numberOfSunkShips++;

			if (numberOfSunkShips == battleships::NUMBER_OF_SHIPS)
			{
				return battleships::playerState::DEFEATED;
			}
			else
			{
				return battleships::playerState::SUNK;
			}
		}
		else 
		{
			return battleships::playerState::INJURED;
		}

		enemyMoves[x][y] = 1;
	}
	else
	{
		return battleships::playerState::MISSED;
	}
}

void Player::generateShips() {
	generateShip(4);
	generateShip(3);
	generateShip(3);
	generateShip(2);
	generateShip(2);
	generateShip(2);
	generateShip(1);
	generateShip(1);
	generateShip(1);
	generateShip(1);
}

void Player::generateShip(const int size) {
	int x = 0, y = 0;
	bool isHorizontal = false;

	bool place = false;

	while (place == false)
	{
		x = rand() % battleships::FIELD_SIZE;
		y = rand() % battleships::FIELD_SIZE;

		int horizontal = rand() % 2;

		if (horizontal == 0)
			isHorizontal = true;

		place = checkPlace(x, y, isHorizontal, size);
	}

	if (isHorizontal)
	{
		for (int i = y; i < y + size; i++)
			field[x][i] = 1;
	}
	else
	{
		for (int i = x; i < x + size; i++)
			field[i][y] = 1;
	}

	fleet.push_back(Ship(x, y, size, isHorizontal));
}

bool Player::checkPlace(int x, int y, bool isHorizontal, int size) {
	if (field[x][y] == 1)
		return false;

	if (isHorizontal) {
		//check if the ship fits
		if (y > battleships::FIELD_SIZE - size)
			return false;
		for (int i = y + 1; i < y + size; i++)
		{
			if (field[x][i] == 1)
				return false;
		}

		//check if cells around the ship are empty
		for (int i = x - 1; i < x + 2; i++)
		{
			if (i > -1 && i < battleships::FIELD_SIZE)
			{
				for (int j = y - 1; j < y + size + 1; j++)
				{
					if (j > -1 && j < battleships::FIELD_SIZE)
					{
						if (field[i][j] == 1)
							return false;
					}
				}
			}
		}
	}
	else
	{
		if (x > 10 - size)
			return false;

		//check if the ship fits
		for (int i = x + 1; i < x + size; i++)
		{
			if (field[i][y] == 1)
				return false;
		}

		//check if cells around the ship are empty
		for (int i = x - 1; i < x + size + 1; i++)
		{
			if (i > -1 && i < battleships::FIELD_SIZE)
			{
				for (int j = y - 1; j < y + 2; j++)
				{
					if (j > -1 && j < battleships::FIELD_SIZE)
					{
						if (field[i][j] == 1)
							return false;
					}
				}
			}
		}
	}

	return true;
}

void Player::setCursorPosition(int column, int row) const
{
	COORD coord;
	coord.X = column;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Player::setInput(char letter, char digit)
{
	this->lastLetter = letter;
	this->lastDigit = digit;
}

int Player::getNumberOfSunkShips()
{
	return 0;
}

bool Player::isAnyShipSunk(int x, int y) const
{
	//TODO:
	return false;
}