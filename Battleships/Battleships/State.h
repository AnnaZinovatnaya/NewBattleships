#ifndef SRC_STATE_H_
#define SRC_STATE_H_

class State
{
public:
	State();
	~State();
	virtual void doJob() = 0;
};

#endif /* SRC_STATE_H_ */
