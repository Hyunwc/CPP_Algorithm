#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	// 플레이어의 포지션을 시작 지점으로
	_pos = board->GetEnterPos();
	_board = board;
}

void Player::Update(uint64 deltaTick)
{
}
