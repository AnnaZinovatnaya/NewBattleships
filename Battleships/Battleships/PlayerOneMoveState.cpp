#include "PlayerOneMoveState.h"

PlayerOneMoveState::PlayerOneMoveState(Battleships * context)
{
	this->context = context;
}


PlayerOneMoveState::~PlayerOneMoveState()
{
}

void PlayerOneMoveState::doJob()
{
	int x = 0;
	int y = 0;

	this->context->getPlayerOne()->makeMove(x, y);

	switch (context->getPlayerTwo()->checkMove(x, y)) {
	case battleships::playerState::INJURED:
		this->context->getPlayerOne()->notifyOnInjured();
		this->context->getMap()->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::SUCCESS);
		this->context->changeState(new PlayerTwoMoveState(this->context));
		break;
	case battleships::playerState::SUNK:
		this->context->getPlayerOne()->notifyOnSunk();
		this->context->getMap()->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::SUCCESS);
		this->context->changeState(new PlayerTwoMoveState(this->context));
		break;
	case battleships::playerState::DEFEATED:
		this->context->getMap()->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::SUCCESS);

		this->context->changeState(new EndOfGameState(this->context));
		break;
	default:
		this->context->getMap()->notifyOnMove(battleships::players::PLAYER_1, x, y, battleships::move::MISS);
		this->context->changeState(new PlayerTwoMoveState(this->context));
		break;
	}
}
