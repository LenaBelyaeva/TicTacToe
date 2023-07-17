#pragma once

#include <memory>

class Player;
class Board;

class AbstractGameModeFactory
{
public:
	AbstractGameModeFactory() = default;
	virtual ~AbstractGameModeFactory() = default;

	virtual std::shared_ptr<Player> createPlayer1(const std::shared_ptr<Board> &board) const = 0;
	virtual std::shared_ptr<Player> createPlayer2(const std::shared_ptr<Board> &board) const = 0;
};
