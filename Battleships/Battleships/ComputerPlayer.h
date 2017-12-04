#ifndef SRC_COMPUTERPLAYER_H_
#define SRC_COMPUTERPLAYER_H_

#include "Player.h"

class ComputerPlayer 
: public Player {
public:
	ComputerPlayer();
	~ComputerPlayer();

	void makeMove(int & x, int & y);
private:
	std::vector<std::vector<int> > moves;
};

#endif /* SRC_COMPUTERPLAYER_H_ */