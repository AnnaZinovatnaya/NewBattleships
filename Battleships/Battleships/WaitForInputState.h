#ifndef SRC_WAITFORINPUTSTATE_H_
#define SRC_WAITFORINPUTSTATE_H_

#include "State.h"

#include "Battleships.h"
#include "PauseState.h"
#include "PlayerOneMoveState.h"

class WaitForInputState :
	public State
{
public:
	WaitForInputState(class Battleships * context);
	~WaitForInputState();

	void doJob();

private:
	class Battleships * context;

	bool isLetter(char input);
	bool isDigit(char input);

	void setCursorPosition(int column, int row) const;
};

#endif /* SRC_WAITFORINPUTSTATE_H_ */
