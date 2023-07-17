#include "GameManager.h"

#include "Board.h"
#include "ComputerModeFactory.h"
#include "GameController.h"
#include "Player.h"
#include "PlayersModeFactory.h"

GameManager::GameManager(QObject *parent)
    : QObject(parent)
{
	createFactory();
}

GameManager::~GameManager()
{
}

void GameManager::restart()
{
	emit gameAboutToRestart();

	m_board.reset(new Board);
	m_player1 = m_factory->createPlayer1(m_board);
	m_player2 = m_factory->createPlayer2(m_board);
	m_controller.reset(new GameController(m_player1, m_player2, m_board));

	emit gameRestarted();
}

std::shared_ptr<Board> GameManager::board() const
{
	return m_board;
}

std::shared_ptr<Player> GameManager::player1() const
{
	return m_player1;
}

std::shared_ptr<Player> GameManager::player2() const
{
	return m_player2;
}

std::shared_ptr<GameController> GameManager::controller() const
{
	return m_controller;
}

GameMode::EGameMode GameManager::gameMode() const
{
	return m_gameMode;
}

void GameManager::setGameMode(GameMode::EGameMode mode)
{
	m_gameMode = mode;
	createFactory();
	restart();
}

void GameManager::createFactory()
{
	switch (m_gameMode) {
	case GameMode::EGameMode::Computer: {
		m_factory = std::make_unique<ComputerModeFactory>();
		break;
	}
	case GameMode::EGameMode::Players: {
		m_factory = std::make_unique<PlayersModeFactory>();
		break;
	}
	}
}
