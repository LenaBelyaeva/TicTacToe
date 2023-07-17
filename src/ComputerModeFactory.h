#pragma once

#include "AbstractGameModeFactory.h"

class ComputerModeFactory : public AbstractGameModeFactory
{
public:
	std::shared_ptr<Player> createPlayer1(const std::shared_ptr<Board> &board) const override;
	std::shared_ptr<Player> createPlayer2(const std::shared_ptr<Board> &board) const override;
};
