#include "PlayersModeFactory.h"

#include "HumanPlayer.h"

std::shared_ptr<Player> PlayersModeFactory::createPlayer1(const std::shared_ptr<Board> &board) const
{
	auto player = std::make_shared<HumanPlayer>(board, "Player 1");
	player->setMark(PlayerMark::EPlayerMark::Cross);
	return player;
}

std::shared_ptr<Player> PlayersModeFactory::createPlayer2(const std::shared_ptr<Board> &board) const
{
	auto player = std::make_shared<HumanPlayer>(board, "Player 2");
	player->setMark(PlayerMark::EPlayerMark::Circle);
	return player;
}
