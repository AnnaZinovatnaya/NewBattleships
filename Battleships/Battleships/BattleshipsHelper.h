#ifndef SRC_BATTLESHIPSHELPER_H_
#define SRC_BATTLESHIPSHELPER_H_

#include <Windows.h>
#include <conio.h>

namespace battleships {
	const int FIELD_SIZE = 10;
	const int NUMBER_OF_SHIPS = 10;

	const int USER_INPUT_ROW = 17;

	enum playerState {
		MISSED = 0,
		INJURED = 1,
		SUNK = 2,
		DEFEATED = 3
	};

	enum players {
		PLAYER_1 = 1,
		PLAYER_2 = 2
	};

	enum move {
		MISS = 0,
		SUCCESS = 1,
	};

	class Helper
	{
	public:
		inline static void setCursorPosition(int column, int row) 
		{
			COORD coord;
			coord.X = column;
			coord.Y = row;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}

		inline static void waitForEnterPressed()
		{
			char keyPressed = 0;
			const char ENTER_KEY = '\r';

			while (ENTER_KEY != keyPressed)
			{
				keyPressed = _getch();
			}
		}
	};
}

#endif /* SRC_BATTLESHIPSHELPER_H_ */