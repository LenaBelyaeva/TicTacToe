#pragma once

#include <QObject>

#include "PlayerMarkEnum.h"

class Player : public QObject
{
	Q_OBJECT

public:
	explicit Player(QString playerName, QObject *parent = nullptr);
	~Player() override;

	virtual bool isInputAllowed() const = 0;
	virtual void setIsInputAllowed(bool isAllowed) = 0;

	virtual void makeMove(int index) = 0;

	QString name() const;
	int score() const;
	PlayerMark::EPlayerMark mark() const;

	void setScore(int newScore);
	void setMark(PlayerMark::EPlayerMark newMark);

signals:
	void isInputAllowedChanged();
	void scoreChanged();
	void markChanged();

protected:
	QString m_name;
	PlayerMark::EPlayerMark m_mark;
	int m_score = 0;
};
