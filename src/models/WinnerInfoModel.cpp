#include "WinnerInfoModel.h"

WinnerInfoModel::WinnerInfoModel(const QString &winnerName, QObject *parent)
    : QObject(parent)
{
	m_message = winnerName.isEmpty() ? "Draw!" : QString("%1 won!").arg(winnerName);
}

WinnerInfoModel::~WinnerInfoModel()
{
}

void WinnerInfoModel::setVisible(bool visible)
{
	if (m_visible == visible) {
		return;
	}

	m_visible = visible;
	emit visibleChanged();
}

bool WinnerInfoModel::visible() const
{
	return m_visible;
}

QString WinnerInfoModel::message() const
{
	return m_message;
}
