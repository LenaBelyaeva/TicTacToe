#include "HumanPlayer.h"

#include "Board.h"

HumanPlayer::HumanPlayer(std::shared_ptr<Board> board, QObject *parent)
    : Player("Player", parent)
    , m_board(board)
{
}

HumanPlayer::HumanPlayer(std::shared_ptr<Board> board, QString playerName, QObject *parent)
    : Player(playerName, parent)
    , m_board(board)
{
}

HumanPlayer::~HumanPlayer()
{
}

bool HumanPlayer::isInputAllowed() const
{
	return m_isInputAllowed;
}

void HumanPlayer::setIsInputAllowed(bool isAllowed)
{
	if (m_isInputAllowed == isAllowed) {
		return;
	}

	m_isInputAllowed = isAllowed;
	emit isInputAllowedChanged();
}

void HumanPlayer::makeMove(int index)
{
	if (isInputAllowed()) {
		m_board->setMark(mark(), index);
	}
}
