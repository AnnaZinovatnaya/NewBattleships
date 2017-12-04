#ifndef SRC_BATTLESHIPSHELPER_H_
#define SRC_BATTLESHIPSHELPER_H_

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
}

#endif /* SRC_BATTLESHIPSHELPER_H_ */