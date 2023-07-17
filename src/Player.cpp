#include "Player.h"

Player::Player(QString playerName, QObject *parent)
    : QObject(parent)
    , m_name(playerName)
{
}

Player::~Player()
{
}

QString Player::name() const
{
	return m_name;
}

int Player::score() const
{
	return m_score;
}

void Player::setScore(int newScore)
{
	if (m_score == newScore) {
		return;
	}

	m_score = newScore;
	emit scoreChanged();
}

PlayerMark::EPlayerMark Player::mark() const
{
	return m_mark;
}

void Player::setMark(PlayerMark::EPlayerMark newMark)
{
	if (m_mark == newMark) {
		return;
	}

	m_mark = newMark;
	emit markChanged();
}
