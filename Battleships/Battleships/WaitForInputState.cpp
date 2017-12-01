#include "WaitForInputState.h"



WaitForInputState::WaitForInputState(Battleships * context)
{
	this->context = context;
}


WaitForInputState::~WaitForInputState()
{
}

void WaitForInputState::doJob()
{
	char input1 = _getch();
	putchar(input1);

	if ('p' == input1)
	{
		this->context->changeState(new PauseState(this->context));
	}
	else
	{
		char input2 = _getch();
		putchar(input2);

		char input3 = _getch();
		putchar(input3);

		if (isLetter(input1) && isDigit(input2) && '\r' == input3)
		{
			this->context->getPlayerOne()->setInput(input1, input2);
			this->context->changeState(new PlayerOneMoveState(this->context));
		} 
	}
}

bool WaitForInputState::isLetter(char input)
{
	if (input >= 'A' && input <= 'J')
		return true;

	if (input >= 'a' && input <= 'j')
		return true;

	return false;
}

bool WaitForInputState::isDigit(char input)
{
	if (input >= '0' && input <= '9')
		return true;

	return false;
}
