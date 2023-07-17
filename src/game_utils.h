#pragma once

#include "PlayerMarkEnum.h"

namespace game_utils {

bool hasEmptyCells(const QVector<PlayerMark::EPlayerMark>& board);
PlayerMark::EPlayerMark winnerOrNone(const QVector<PlayerMark::EPlayerMark>& board);
PlayerMark::EPlayerMark isSameMark(const QVector<PlayerMark::EPlayerMark>& board, QVector<int> vIndex);

}
