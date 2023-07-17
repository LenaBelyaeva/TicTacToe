#pragma once

#include <QObject>

#include <memory>

class Player;
class Board;

class GameController : public QObject
{
	Q_OBJECT

public:
	explicit GameController(
	        std::shared_ptr<Player> player1,
	        std::shared_ptr<Player> player2,
	        std::shared_ptr<Board> board,
	        QObject *parent = nullptr);

	std::shared_ptr<Player> currentTurn() const;
	std::shared_ptr<Player> winner() const;
	bool isGameFinished() const;

	void startGame();

signals:
	void waitingForMove();
	void currentTurnChanged();
	void isGameFinishedChanged();
	void winnerChanged();

private slots:
	void onBoardChanged();

private:
	void setWinner(const std::shared_ptr<Player> &player);
	void setIsGameFinished(bool isFinished);
	void setCurrentTurn(const std::shared_ptr<Player> &player);

	void changeTurn();
	bool checkIsGameFinished();

	bool m_isGameFinished = false;
	std::shared_ptr<Player> m_winner;
	std::shared_ptr<Player> m_currentTurn;
	std::shared_ptr<Player> m_player1;
	std::shared_ptr<Player> m_player2;
	std::shared_ptr<Board> m_board;
};
