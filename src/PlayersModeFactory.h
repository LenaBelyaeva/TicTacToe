#pragma once

#include <memory>

#include "AbstractGameModeFactory.h"

class PlayersModeFactory : public AbstractGameModeFactory
{
public:
	std::shared_ptr<Player> createPlayer1(const std::shared_ptr<Board> &board) const override;
	std::shared_ptr<Player> createPlayer2(const std::shared_ptr<Board> &board) const override;
};
