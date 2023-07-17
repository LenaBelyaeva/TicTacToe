#include "ComputerModeFactory.h"

#include "Board.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"

std::shared_ptr<Player> ComputerModeFactory::createPlayer1(const std::shared_ptr<Board> &board) const
{
	auto player = std::make_shared<HumanPlayer>(board);
	player->setMark(PlayerMark::EPlayerMark::Cross);
	return player;
}

std::shared_ptr<Player> ComputerModeFactory::createPlayer2(const std::shared_ptr<Board> &board) const
{
	auto player = std::make_shared<ComputerPlayer>(board);
	player->setMark(PlayerMark::EPlayerMark::Circle);
	return player;
}
