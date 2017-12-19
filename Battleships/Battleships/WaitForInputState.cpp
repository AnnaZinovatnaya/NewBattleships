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
	bool correctInput = false;

	while (!correctInput) 
	{
		char input1 = _getch();
		putchar(input1);

		if ('p' == input1)
		{
			this->context->changeState(new PauseState(this->context));
			correctInput = true;
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

				battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW);
				std::cout << "   ";
				battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW);

				this->context->changeState(new PlayerOneMoveState(this->context));

				correctInput = true;
			}
			else
			{
				battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW);
				std::cout << "Incorrect input!";
				Sleep(1000);
				battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW);
				std::cout << "                ";
				battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW);
			}
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