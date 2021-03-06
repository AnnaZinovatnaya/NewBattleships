#include "PauseState.h"



PauseState::PauseState(Battleships * context)
{
	this->context = context;
}


PauseState::~PauseState()
{
}

void PauseState::doJob()
{
	clock_t startPauseTime = clock();

	battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW);
	std::cout << " ";
	battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW + 1);
	std::cout << "PAUSED" << std::endl;
	std::cout << "Time: 0 minute(s) 0 second(s)" << std::endl;
	std::cout << "Press ENTER to continue";

	clock_t pause0 = clock();
	clock_t pause1;

	int oldTime = 0;
	int newTime = 0;
	int minutes = 0;
	
	while (!listenKeyPress(VK_RETURN))
	{
		pause1 = clock();
		newTime = static_cast<int>(pause1 - pause0) / CLOCKS_PER_SEC;
		if (newTime != oldTime) 
		{	
			battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW + 2);
			int minutes = static_cast<int>(newTime / 60);
			std::cout << "Time: " << minutes << " minute(s) " << newTime - (minutes * 60) << " second(s)      " << std::endl;
			oldTime = newTime;
		}	
	}

	battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW + 1);
	std::cout << "      ";
	battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW + 2);
	std::cout << "                                      ";
	battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW + 3);
	std::cout << "                                      ";
	battleships::Helper::setCursorPosition(0, battleships::USER_INPUT_ROW);
	this->context->returnPreviousState();
}

bool PauseState::listenKeyPress(short p_key)
{

	const unsigned short MSB = 0x8000;

	if (GetAsyncKeyState(p_key) & MSB)
	{
		return true;
	}
	else 
	{
		return false;
	}
}