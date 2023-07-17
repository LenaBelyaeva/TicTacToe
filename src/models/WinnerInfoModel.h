#pragma once

#include <QObject>

class WinnerInfoModel : public QObject
{
	Q_OBJECT

	Q_PROPERTY(bool visible READ visible WRITE setVisible NOTIFY visibleChanged)
	Q_PROPERTY(QString message READ message CONSTANT)

public:
	explicit WinnerInfoModel(const QString &winnerName, QObject *parent = nullptr);
	~WinnerInfoModel() override;

	bool visible() const;
	void setVisible(bool visible);

	QString message() const;

signals:
	bool visibleChanged();

private:
	QString m_message;
	bool m_visible = false;
};
