#pragma once

#include <QObject>

class PlayerMark
{
	Q_GADGET

public:
	enum class EPlayerMark {
		None,
		Cross,
		Circle
	};
	Q_ENUM(EPlayerMark)

private:
	PlayerMark() {}
};
