#pragma once

#include <QObject>

class GameMode
{
	Q_GADGET

public:
	enum class EGameMode {
		Computer,
		Players
	};
	Q_ENUM(EGameMode)

private:
	GameMode() {}
};
