#ifndef SRC_PAUSESATE_H_
#define SRC_PAUSESATE_H_

#include "State.h"

#include "Battleships.h"

class PauseState :
	public State
{
public:
	PauseState(class Battleships * context);
	~PauseState();

	void doJob();
private:
	class Battleships * context;
};

#endif /* SRC_PAUSESATE_H_ */
