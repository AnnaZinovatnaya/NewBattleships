#ifndef SRC_PLAYERONEMOVESTATE_H_
#define SRC_PLAYERONEMOVESTATE_H_

#include "State.h"
#include "Battleships.h"
#include "PlayerTwoMoveState.h"
#include "EndOfGameState.h"

class PlayerOneMoveState :
	public State
{
public:
	PlayerOneMoveState(class Battleships * context);
	~PlayerOneMoveState();

	void doJob();
private:
	class Battleships * context;

	void setCursorPosition(int column, int row) const;
	void printSunkMessage();
};

#endif /* SRC_PLAYERONEMOVESTATE_H_ */

