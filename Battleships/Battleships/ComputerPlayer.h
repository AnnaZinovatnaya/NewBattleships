#ifndef SRC_COMPUTERPLAYER_H_
#define SRC_COMPUTERPLAYER_H_

#include "Player.h"

class ComputerPlayer 
: public Player {
public:
	ComputerPlayer();
	~ComputerPlayer();

	void makeMove(int & x, int & y);
};

#endif /* SRC_COMPUTERPLAYER_H_ */