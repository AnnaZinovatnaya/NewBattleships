#ifndef SRC_PAUSESATE_H_
#define SRC_PAUSESATE_H_

#include "Battleships.h"
#include "State.h"

class PauseState :
	public State
{
public:
	PauseState(class Battleships * context);
	~PauseState();

	void doJob();
private:
	class Battleships * context;

	void setCursorPosition(int column, int row) const;
	bool listenKeyPress(short p_key);
};

#endif /* SRC_PAUSESATE_H_ */
