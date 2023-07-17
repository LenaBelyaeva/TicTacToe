#include "GameController.h"

#include "Player.h"
#include "Board.h"

#include "game_utils.h"

namespace  {

bool hasWinner(const QVector<PlayerMark::EPlayerMark>& board)
{
	PlayerMark::EPlayerMark mark = game_utils::winnerOrNone(board);
	return mark != PlayerMark::EPlayerMark::None;
}

}

GameController::GameController(
        std::shared_ptr<Player> player1,
        std::shared_ptr<Player> player2,
        std::shared_ptr<Board> board,
        QObject *parent)
    : QObject(parent)
    , m_player1(std::move(player1))
    , m_player2(std::move(player2))
    , m_board(std::move(board))
{
	connect(m_board.get(), &Board::boardChanged, this, &GameController::onBoardChanged);
}

std::shared_ptr<Player> GameController::currentTurn() const
{
	return m_currentTurn;
}

std::shared_ptr<Player> GameController::winner() const
{
	return m_winner;
}

bool GameController::isGameFinished() const
{
	return m_isGameFinished;
}

void GameController::startGame()
{
	if (m_player1->mark() == PlayerMark::EPlayerMark::Cross) {
		setCurrentTurn(m_player1);
	} else if (m_player2->mark() == PlayerMark::EPlayerMark::Cross){
		setCurrentTurn(m_player2);
	} else {
		Q_ASSERT(false);
	}
}

void GameController::onBoardChanged()
{
	if (hasWinner(m_board->board())) {
		setWinner(m_currentTurn);
		setIsGameFinished(true);
		return;
	}

	if (!game_utils::hasEmptyCells(m_board->board())) {
		setIsGameFinished(true);
		return;
	}

	changeTurn();
}

void GameController::setWinner(const std::shared_ptr<Player> &player)
{
	m_winner = player;
	emit winnerChanged();
}

void GameController::setIsGameFinished(bool isFinished)
{
	m_isGameFinished = isFinished;
	emit isGameFinishedChanged();
}

void GameController::setCurrentTurn(const std::shared_ptr<Player> &player)
{
	m_currentTurn = player;

	m_player1->setIsInputAllowed(m_currentTurn == m_player1);
	m_player2->setIsInputAllowed(m_currentTurn == m_player2);

	emit currentTurnChanged();
}

void GameController::changeTurn()
{
	setCurrentTurn(m_currentTurn == m_player1 ? m_player2 : m_player1);
}
