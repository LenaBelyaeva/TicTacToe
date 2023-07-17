#include "GuiModel.h"

#include "Board.h"
#include "ComputerModeFactory.h"
#include "GameController.h"
#include "GameManager.h"
#include "Player.h"
#include "PlayersModeFactory.h"
#include "models/GameGridModel.h"
#include "models/WinnerInfoModel.h"

GuiModel::GuiModel(QObject *parent)
    : QObject(parent)
    , m_gameManager(new GameManager)
{
	connect(m_gameManager, &GameManager::gameRestarted, this, &GuiModel::onGameRestarted);

	m_gameManager->restart();
}

GuiModel::~GuiModel()
{
}

QObject *GuiModel::gridModel() const
{
	return m_gridModel.get();
}

QObject *GuiModel::winnerInfoModel() const
{
	return m_infoModel.get();
}

GameMode::EGameMode GuiModel::gameMode() const
{
	return m_gameManager->gameMode();
}

void GuiModel::setGameMode(GameMode::EGameMode mode)
{
	if (gameMode() == mode) {
		return;
	}

	m_gameManager->setGameMode(mode);
	emit gameModeChanged();
}

void GuiModel::restartGame()
{
	m_gameManager->restart();
}

void GuiModel::onGameFinished()
{
	showWinnerInfo();
}

void GuiModel::onGameRestarted()
{
	connect(m_gameManager->controller().get(), &GameController::isGameFinishedChanged,
	        this, &GuiModel::onGameFinished);

	m_gridModel.reset(new GameGridModel(m_gameManager->controller(), m_gameManager->board()));
	m_infoModel.reset();
	m_gameManager->controller()->startGame();

	emit gridModelChanged();
	emit winnerInfoModelChanged();
}

void GuiModel::showWinnerInfo()
{
	auto winner = m_gameManager->controller()->winner();
	m_infoModel.reset(new WinnerInfoModel(winner ? winner->name() : ""));
	m_infoModel->setVisible(true);
	emit winnerInfoModelChanged();
}
