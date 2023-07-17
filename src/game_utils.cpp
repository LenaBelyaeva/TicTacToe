#include "game_utils.h"

namespace  {

using Mark = PlayerMark::EPlayerMark;

}

Mark game_utils::winnerOrNone(const QVector<Mark> &board)
{
	static const QVector<QVector<int>> winningCells = {
	    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
	    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
	    {0, 4, 8}, {2, 4, 6}
	};

	for (const auto& vCells : winningCells) {
		const auto mark = isSameMark(board, vCells);
		if (mark != Mark::None) {
			return mark;
		}
	}
	return Mark::None;
}

bool game_utils::hasEmptyCells(const QVector<Mark> &board)
{
	bool hasEmptyCell = false;
	for (auto& cell : board) {
		hasEmptyCell |= cell == Mark::None;
		if (hasEmptyCell) {
			return true;
		}
	}
	return false;
}

Mark game_utils::isSameMark(const QVector<Mark> &board, QVector<int> vIndex)
{
	bool res = true;
	auto mark = board.at(vIndex.first());
	for (const auto index : vIndex) {
		res &= mark == board.at(index);
	}
	if (res) {
		return mark;
	}
	return Mark::None;
}
