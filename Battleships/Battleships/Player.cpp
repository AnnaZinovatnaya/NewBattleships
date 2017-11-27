#include "Player.h"

Player::Player() {
	std::vector<int> row(10, 0);
	std::vector<std::vector<int> > field(10, row);

	this->field = field;

	generateShips();

	//------------------------------------
	myfile.open("log.txt", std::ios::app);
	myfile.clear();
	//------------------------------------

	myfile << "Generated ships:\n\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			myfile << this->field[i][j];
		myfile << "\n";
	}
	myfile << "\n";
			
}

Player::~Player() {
	//------------------------------------
	myfile.close();
	//------------------------------------
}

void Player::makeMove(int & x, int & y) {
	char charHumanHit[3] = { "00" };
	int humanHit[2] = { 0,0 };

	charHumanHit[0] = _getch();
	putchar(charHumanHit[0]);

	charHumanHit[1] = _getch();
	putchar(charHumanHit[1]);

	charHumanHit[2] = _getch();
	putchar(charHumanHit[2]);

	setCursorPosition(0, 17);

	std::cout << "   ";

	setCursorPosition(0, 17);

	humanHit[0] = charHumanHit[0] % '0';

	if (charHumanHit[1] >= 'A' && charHumanHit[1] <= 'J')
	{
		humanHit[1] = charHumanHit[1] % 'A';
	}
	else
	{
		humanHit[1] = charHumanHit[1] % 'a';
	}

	x = humanHit[0];
	y = humanHit[1];

	myfile << "Human hit: " << x << " " << y << "\n";
}

std::vector<std::vector<int> > Player::getField() {
	return field;
}

void Player::notifyOnInjured() {

}

void Player::notifyOnSunk() {

}

int Player::checkMove(int x, int y) {
	if (1 == field[y][y])
		return battleships::playerState::INJURED;
	else
		return battleships::playerState::MISSED;
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
		x = rand() % 10;
		y = rand() % 10;

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
}

bool Player::checkPlace(int x, int y, bool isHorizontal, int size) {
	if (field[x][y] == 1)
		return false;

	if (isHorizontal) {
		//check if the ship fits
		if (y > 10 - size)
			return false;
		for (int i = y + 1; i < y + size; i++)
		{
			if (field[x][i] == 1)
				return false;
		}

		//check if cells around the ship are empty
		for (int i = x - 1; i < x + 2; i++)
		{
			if (i > -1 && i < 10)
			{
				for (int j = y - 1; j < y + size + 1; j++)
				{
					if (j > -1 && j < 10)
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
			if (i > -1 && i < 10)
			{
				for (int j = y - 1; j < y + 2; j++)
				{
					if (j > -1 && j < 10)
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