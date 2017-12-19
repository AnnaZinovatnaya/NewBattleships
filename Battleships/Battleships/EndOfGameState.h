#ifndef SRC_ENDOFGAMESATE_H_
#define SRC_ENDOFGAMESATE_H_

#include "Battleships.h"
#include "State.h"

class EndOfGameState :
	public State
{
public:
	EndOfGameState(class Battleships * context);
	~EndOfGameState();

	void doJob();
private:
	class Battleships * context;
};

#endif /* SRC_ENDOFGAMESATE_H_ */
