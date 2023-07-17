#pragma once

#include <QObject>

#include "Player.h"

class Board;

class ComputerPlayer : public Player
{
	Q_OBJECT

public:
	explicit ComputerPlayer(std::shared_ptr<Board> board, QObject *parent = nullptr);
	~ComputerPlayer() override;

	bool isInputAllowed() const override;
	void setIsInputAllowed(bool isAllowed) override;

	void makeMove(int) override;

private:
	void emulateMove();

	std::shared_ptr<Board> m_board;
};

