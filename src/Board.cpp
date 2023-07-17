#include "Board.h"

Board::Board(QObject *parent)
    : QObject(parent)
    , m_cells(QVector(9, PlayerMark::EPlayerMark::None))
{
}

Board::~Board()
{
}

QVector<PlayerMark::EPlayerMark> Board::board() const
{
	return m_cells;
}

void Board::setMark(PlayerMark::EPlayerMark mark, int index)
{
	if (index >= m_cells.size()) {
		Q_ASSERT(false);
		return;
	}

	m_cells[index] = mark;
	emit boardChanged();
}
