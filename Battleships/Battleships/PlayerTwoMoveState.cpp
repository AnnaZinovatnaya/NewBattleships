#include "PlayerTwoMoveState.h"



PlayerTwoMoveState::PlayerTwoMoveState(class Battleships * context)
{
	this->context = context;
}



PlayerTwoMoveState::~PlayerTwoMoveState()
{
}

void PlayerTwoMoveState::doJob()
{

	int x = 0;
	int y = 0;

	this->context->getPlayerTwo()->makeMove(x, y);

	switch (context->getPlayerOne()->checkMove(x, y)) {
	case battleships::playerState::INJURED:
		this->context->getPlayerTwo()->notifyOnInjured();
		this->context->getMap()->notifyOnMove(battleships::players::PLAYER_2, x, y, battleships::move::SUCCESS);
		this->context->changeState(new WaitForInputState(this->context));
		break;
	case battleships::playerState::SUNK:
		this->context->getPlayerTwo()->notifyOnSunk();
		this->context->getMap()->notifyOnMove(battleships::players::PLAYER_2, x, y, battleships::move::SUCCESS);
		this->context->changeState(new WaitForInputState(this->context));
		break;
	case battleships::playerState::DEFEATED:
		this->context->getMap()->notifyOnMove(battleships::players::PLAYER_2, x, y, battleships::move::SUCCESS);

		this->context->changeState(new EndOfGameState(this->context));
		break;
	default:
		this->context->getMap()->notifyOnMove(battleships::players::PLAYER_2, x, y, battleships::move::MISS);
		this->context->changeState(new WaitForInputState(this->context));
		break;
	}
}
