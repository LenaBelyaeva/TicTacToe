#pragma once

#include <QObject>

#include "GameModeEnum.h"

class AbstractGameModeFactory;
class Board;
class GameController;
class Player;

class GameManager : public QObject
{
	Q_OBJECT

public:
	GameManager(QObject *parent = nullptr);
	~GameManager() override;

	void restart();

	std::shared_ptr<Board> board() const;
	std::shared_ptr<Player> player1() const;
	std::shared_ptr<Player> player2() const;
	std::shared_ptr<GameController> controller() const;

	GameMode::EGameMode gameMode() const;
	void setGameMode(GameMode::EGameMode mode);

signals:
	void gameAboutToRestart();
	void gameRestarted();

private:
	void createFactory();

	std::shared_ptr<Board> m_board;
	std::shared_ptr<Player> m_player1;
	std::shared_ptr<Player> m_player2;
	std::shared_ptr<GameController> m_controller;
	std::unique_ptr<AbstractGameModeFactory> m_factory;
	GameMode::EGameMode m_gameMode = GameMode::EGameMode::Computer;
};
