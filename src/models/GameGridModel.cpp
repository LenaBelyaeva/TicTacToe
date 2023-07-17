#include "GameGridModel.h"

#include <QUrl>

#include "../GameController.h"
#include "../Board.h"
#include "../Player.h"

namespace  {

QString imageSource(PlayerMark::EPlayerMark cellType) {
	switch (cellType) {
	case PlayerMark::EPlayerMark::Circle:
		return { "qrc:/images/circle.svg" };
	case PlayerMark::EPlayerMark::Cross:
		return { "qrc:/images/cross.svg" };
	default:
		return {};

	}
}

}

GameGridModel::GameGridModel(
        const std::shared_ptr<GameController> &controller,
        const std::shared_ptr<Board> &board,
        QObject *parent)
    : QAbstractListModel(parent)
    , m_controller(controller)
    , m_board(board)
{
	connect(board.get(), &Board::boardChanged, this, &GameGridModel::onBoardChanged);
	connect(controller.get(), &GameController::isGameFinishedChanged, this, &GameGridModel::onEditableChanged);
	connect(controller.get(), &GameController::isGameFinishedChanged, this, &GameGridModel::onCurrentTurnChanged);
	connect(controller.get(), &GameController::currentTurnChanged, this, &GameGridModel::onCurrentTurnChanged);
}

QHash<int, QByteArray> GameGridModel::roleNames() const
{
	return {
		{ ImageSource, "imageSource"},
		{ IsEditable , "isEditable"}
	};
}

int GameGridModel::rowCount(const QModelIndex &) const
{
	return 9;
}

QVariant GameGridModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || index.row() >= rowCount()) {
		Q_ASSERT(false);
		return {};
	}

	auto controllerPtr = m_controller.lock();
	auto boardPtr = m_board.lock();

	if (!controllerPtr || !boardPtr) {
		return {};
	}

	switch (role) {
	case ImageSource: {
		return QVariant::fromValue(imageSource(boardPtr->board()[index.row()]));
	}
	case IsEditable: {
		const bool res = !controllerPtr->isGameFinished()
		        && (boardPtr->board())[index.row()] == PlayerMark::EPlayerMark::None;
		return QVariant::fromValue(res);
	}
	}

	Q_ASSERT(false);
	return {};
}

QString GameGridModel::currentTurn() const
{
	return m_currentTurn;
}

void GameGridModel::makeMove(int index)
{
	auto controllerPtr = m_controller.lock();
	if (!controllerPtr) {
		return;
	}

	auto player = controllerPtr->currentTurn();
	if (player) {
		player->makeMove(index);
	}
}

void GameGridModel::onBoardChanged()
{
	emit dataChanged(index(0), index(rowCount() - 1), { ImageSource, IsEditable });
}

void GameGridModel::onEditableChanged()
{
	emit dataChanged(index(0), index(rowCount() - 1), { IsEditable });
}

void GameGridModel::onCurrentTurnChanged()
{
	auto controllerPtr = m_controller.lock();
	if (!controllerPtr) {
		setCurrentTurn({});
		return;
	}

	if(controllerPtr->isGameFinished()) {
		setCurrentTurn({});
		return;
	}

	auto player = controllerPtr->currentTurn();
	if (!player) {
		setCurrentTurn({});
		return;
	}

	setCurrentTurn(QString(player->name()) + " turn!");
}

void GameGridModel::setCurrentTurn(const QString &text)
{
	if (m_currentTurn == text) {
		return;
	}

	m_currentTurn = text;
	emit currentTurnChanged();
}
