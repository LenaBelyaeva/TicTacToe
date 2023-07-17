#include "ComputerPlayer.h"

#include <QTimer>

#include <algorithm>

#include "Board.h"
#include "game_utils.h"

namespace  {

using Mark = PlayerMark::EPlayerMark;

struct Game {
	void makeMove(int index) {
		board[index] = turn;
		turn = turn == player ? opponent : player;
	}

	QVector<Mark> board;
	Mark player;
	Mark opponent;
	Mark turn;
};

int score(const Game& game, Mark winner)
{
	if (winner == game.player) {
		return 10;
	} else if (winner == game.opponent) {
		return -10;
	} else {
		return 0;
	}
}

QVector<int> possibleMoves(const QVector<Mark>& board)
{
	QVector<int> res;
	for (int i = 0; i < board.size(); i++) {
		if (board[i] == Mark::None) {
			res.push_back(i);
		}
	}
	return res;
}

//  @return <move, score>
std::pair<int, int> minimax(Game game)
{
	Mark winner = game_utils::winnerOrNone(game.board);
	if (winner != Mark::None || !game_utils::hasEmptyCells(game.board)) {
		return { -1, score(game, winner) };
	}

	QVector<int> moves;
	QVector<int> scores;

	moves = possibleMoves(game.board);
	for (int move : qAsConst(moves)) {
		Game newState = game;
		newState.makeMove(move);
		scores.push_back(minimax(newState).second);
	}

	if (game.turn == game.player) {
		auto result = std::max_element(scores.begin(), scores.end());
		int index = std::distance(scores.begin(), result);
		return { moves[index], *result };
	} else {
		auto result = std::min_element(scores.begin(), scores.end());
		int index = std::distance(scores.begin(), result);
		return { moves[index], *result };
	}
}

int calculateMove(const QVector<PlayerMark::EPlayerMark>& board, Mark mark)
{
	Game game;
	game.board = board;
	game.player = mark;
	game.opponent = mark == Mark::Cross ? Mark::Circle :Mark::Cross;
	game.turn = mark;

	return minimax(game).first;
}

}

ComputerPlayer::ComputerPlayer(std::shared_ptr<Board> board, QObject *parent)
    : Player("Computer", parent)
    , m_board(std::move(board))
{
}

ComputerPlayer::~ComputerPlayer()
{
}

bool ComputerPlayer::isInputAllowed() const
{
	return false;
}

void ComputerPlayer::setIsInputAllowed(bool isAllowed)
{
	if (isAllowed) {
		QTimer::singleShot(200, this, &ComputerPlayer::emulateMove);
	}
}

void ComputerPlayer::makeMove(int)
{
}

void ComputerPlayer::emulateMove()
{
	int index = calculateMove(m_board->board(), mark());
	m_board->setMark(mark(), index);
}
