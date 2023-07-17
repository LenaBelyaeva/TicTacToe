#pragma once

#include <QObject>
#include <QPointer>

#include "GameModeEnum.h"

class GameGridModel;
class GameManager;
class WinnerInfoModel;

class GuiModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QObject *gridModel READ gridModel NOTIFY gridModelChanged)
	Q_PROPERTY(QObject *winnerInfoModel READ winnerInfoModel NOTIFY winnerInfoModelChanged)
	Q_PROPERTY(GameMode::EGameMode gameMode READ gameMode WRITE setGameMode NOTIFY gameModeChanged)

public:
	explicit GuiModel(QObject *parent = nullptr);
	~GuiModel() override;

	QObject *gridModel() const;
	QObject *winnerInfoModel() const;

	GameMode::EGameMode gameMode() const;
	void setGameMode(GameMode::EGameMode mode);

	Q_INVOKABLE void restartGame();

signals:
	void gridModelChanged();
	void winnerInfoModelChanged();
	void gameModeChanged();

private slots:
	void onGameFinished();
	void onGameRestarted();

private:
	void showWinnerInfo();

	std::unique_ptr<GameGridModel> m_gridModel;
	std::unique_ptr<WinnerInfoModel> m_infoModel;
	QPointer<GameManager> m_gameManager;
};
