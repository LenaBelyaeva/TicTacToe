#pragma once

#include <QObject>

#include "Player.h"

class Board;

class HumanPlayer : public Player
{
	Q_OBJECT

public:
	explicit HumanPlayer(
	        std::shared_ptr<Board> board,
	        QObject *parent = nullptr);

	explicit HumanPlayer(
	        std::shared_ptr<Board> board,
	        QString playerName,
	        QObject *parent = nullptr);

	~HumanPlayer() override;

	bool isInputAllowed() const override;
	void setIsInputAllowed(bool isAllowed) override;

	void makeMove(int index) override;

private:
	bool m_isInputAllowed = false;
	std::shared_ptr<Board> m_board;
};

