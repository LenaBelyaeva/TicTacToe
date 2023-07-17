#pragma once

#include <QObject>
#include <QAbstractListModel>

class GameController;
class Board;

class GameGridModel : public QAbstractListModel
{
	Q_OBJECT

	Q_PROPERTY(QString currentTurn READ currentTurn NOTIFY currentTurnChanged)

public:
	enum Roles {
		ImageSource = Qt::DisplayRole,
		IsEditable = Qt::UserRole
	};

	explicit GameGridModel(
	        const std::shared_ptr<GameController> &controller,
	        const std::shared_ptr<Board> &board,
	        QObject *parent = nullptr);

	QHash<int, QByteArray> roleNames() const override;
	int rowCount(const QModelIndex &parent = {}) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	QString currentTurn() const;

	Q_INVOKABLE void makeMove(int index);

signals:
	void currentTurnChanged();

private slots:
	void onBoardChanged();
	void onEditableChanged();
	void onCurrentTurnChanged();

private:
	void setCurrentTurn(const QString& text);

	QString m_currentTurn;
	std::weak_ptr<GameController> m_controller;
	std::weak_ptr<Board> m_board;
};
