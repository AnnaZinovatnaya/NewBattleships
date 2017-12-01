#ifndef SRC_PLAYERTWOMOVESTATE_H_
#define SRC_PLAYERTWOMOVESTATE_H_

#include "State.h"
#include "Battleships.h"
class PlayerTwoMoveState :
	public State
{
public:
	PlayerTwoMoveState(class Battleships * context);
	~PlayerTwoMoveState();

	void doJob();
private:
	class Battleships * context;
};

#endif /* SRC_PLAYERTWOMOVESTATE_H_ */