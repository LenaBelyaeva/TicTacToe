#pragma once

#include <QObject>

#include "PlayerMarkEnum.h"

class Board : public QObject
{
	Q_OBJECT

public:
	explicit Board(QObject *parent = nullptr);
	~Board() override;

	QVector<PlayerMark::EPlayerMark> board() const;
	void setMark(PlayerMark::EPlayerMark mark, int index);

signals:
	void boardChanged();

private:
	QVector<PlayerMark::EPlayerMark> m_cells;
};
